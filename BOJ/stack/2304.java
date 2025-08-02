import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        Block[] blocks = new Block[n];
        
        for (int i=0; i<n; i++) {
            String[] inputs = br.readLine().split(" ");
            int start = Integer.parseInt(inputs[0]);
            int height = Integer.parseInt(inputs[1]);
            blocks[i] = new Block(start, height);
        }
        Arrays.sort(blocks);

        Block maxHeightBlock = blocks[0];
        int maxHeightBlockId = 0;
        for (int i=0; i<n; i++) {
            if (maxHeightBlock.height < blocks[i].height) {
                maxHeightBlock = blocks[i];
                maxHeightBlockId = i;
            }
        }

        int ret = 0;
        
        Stack<Block> st = new Stack<>();
        for (int i=maxHeightBlockId; i>=0; i--) {
            if (!st.empty()) {
                Block top = st.peek();
                if (blocks[i].height <= top.height) {
                    st.add(blocks[i]);
                } else {
                    while (!st.empty()) {
                        top = st.peek();
                        if (blocks[i].height > top.height) {
                            st.pop();
                        } else {
                            break;
                        }
                    }
                    st.add(blocks[i]);
                }
            } else {
                st.add(blocks[i]);
            }
        }

        ret += getArea(st);

        for (int i=maxHeightBlockId; i<n; i++) {
            if (!st.empty()) {
                Block top = st.peek();
                if (blocks[i].height <= top.height) {
                    st.add(blocks[i]);
                } else {
                    while (!st.empty()) {
                        top = st.peek();
                        if (blocks[i].height > top.height) {
                            st.pop();
                        } else {
                            break;
                        }
                    }
                    st.add(blocks[i]);
                }
            } else {
                st.add(blocks[i]);
            }
        }

        ret += getArea(st);

        ret -= maxHeightBlock.height;
        System.out.println(ret);
    }

    static int getArea(Stack<Block> st) {
        if (st.empty()) return 0;

        int ret = 0;

        Block startBlock = st.peek(); st.pop();
        Block lastBlock = startBlock;
        while (!st.empty()) {
            Block nextBlock = st.peek(); st.pop();
            ret += Math.abs(startBlock.start - nextBlock.start) * startBlock.height;
            startBlock = nextBlock;
            lastBlock = nextBlock;
        }

        ret += lastBlock.height;
        return ret;
    }

    static class Block implements Comparable<Block> {
        int start;
        int height;

        public Block(int start, int height) {
            this.start = start;
            this.height = height;
        }

        @Override
        public int compareTo(Block b) {
            return start - b.start;
        }
    }
}