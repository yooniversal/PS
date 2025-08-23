import java.io.*;
import java.util.*;

public class Main {

    static Map<String, Node> nodeMap;

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        nodeMap = new HashMap<>();

        int n = Integer.parseInt(br.readLine());
        Node root = null;
        while (n-- > 0) {
            String[] inputs = br.readLine().split(" ");
            String current = inputs[0];
            String left = inputs[1];
            String right = inputs[2];

            if (!left.equals(".") && nodeMap.get(left) == null) {
                nodeMap.put(left, new Node(left, null, null));
            }
            if (!right.equals(".") && nodeMap.get(right) == null) {
                nodeMap.put(right, new Node(right, null, null));
            }

            Node currentNode = nodeMap.getOrDefault(
                current,
                new Node(current, nodeMap.get(left), nodeMap.get(right))
            );

            if (nodeMap.get(current) == null) {
                nodeMap.put(current, currentNode);
            } else {
                currentNode.left = nodeMap.get(left);
                currentNode.right = nodeMap.get(right);
            }
            if (current.equals("A")) root = currentNode;
        }
        
        root.printPreOrder();
        System.out.println();

        root.printInOrder();
        System.out.println();

        root.printPostOrder();
        System.out.println();
    }

    static class Node {
        String v;
        Node left;
        Node right;

        public Node(String v, Node left, Node right) {
            this.v = v;
            this.left = left;
            this.right = right;
        }

        public void printPreOrder() {
            System.out.print(v);
            if (left != null) left.printPreOrder();
            if (right != null) right.printPreOrder();
        }

        public void printInOrder() {
            if (left != null) left.printInOrder();
            System.out.print(v);
            if (right != null) right.printInOrder();
        }

        public void printPostOrder() {
            if (left != null) left.printPostOrder();
            if (right != null) right.printPostOrder();
            System.out.print(v);
        }
    }
}