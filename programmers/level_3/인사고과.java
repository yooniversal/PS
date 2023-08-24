import java.util.*;

class Solution {
    
    static Stat[] sc;
    
    public int solution(int[][] scores) {
        sc = new Stat[scores.length];
        for(int i=0; i<scores.length; ++i) {
            boolean oh = i == 0 ? true : false;
            sc[i] = new Stat(scores[i][0], scores[i][1], oh);
        }
        
        Arrays.sort(sc, new Comparator<Stat>() {
            @Override
            public int compare(Stat ls, Stat rs) {
                return ls.b - rs.b;
            }
        });
        
        int beforeValue = -1, rank = -1;
        for(int i=0; i<scores.length; ++i) {
            int other = -1;
            if(beforeValue == sc[i].b) {
                other = rank;
            } else {
                beforeValue = sc[i].b;
                rank = i;
                other = i;
            }
            sc[i].other = other;
        }
        
        Arrays.sort(sc, new Comparator<Stat>() {
            @Override
            public int compare(Stat ls, Stat rs) {
                return ls.a - rs.a;
            }
        });
        
        int criteria = sc[0].a;
        int bMax = sc[0].b;
        int[] rMax = new int[100005];
        ArrayList<Integer> leftList = new ArrayList<>();
        leftList.add(criteria);
        
        for(int i=0; i<sc.length; ++i) {
            if(criteria == sc[i].a) {
                bMax = Math.max(bMax, sc[i].b);
                rMax[criteria] = bMax;
                continue;
            }
            
            criteria = sc[i].a;
            bMax = sc[i].b;
            rMax[criteria] = bMax;
            leftList.add(criteria);
        }
        
        int[] leftListId = new int[100005];
        int rightMax = 0;
        for(int i=leftList.size()-1; i>=0; --i) {
            int left = leftList.get(i);
            leftListId[left] = i;
            rightMax = Math.max(rightMax, rMax[left]);
            rMax[left] = rightMax;
        }
        
        for(int i=0; i<sc.length; ++i) {
            if(leftList.size() <= leftListId[sc[i].a] + 1) continue;
            if(sc[i].b >= rMax[leftList.get(leftListId[sc[i].a] + 1)]) continue;
            sc[i].use = false;
        }
        
        Arrays.sort(sc, new Comparator<Stat>() {
            @Override
            public int compare(Stat ls, Stat rs) {
                return (rs.a+rs.b) - (ls.a+ls.b);
            }
        });
        
        beforeValue = -1; rank = 0;
        int skipCnt = 0;
        for(int i=0; i<sc.length; ++i) {
            if(!sc[i].use) {
                skipCnt++;
                continue;
            }
            
            int other = -1;
            if(beforeValue == sc[i].a + sc[i].b) {
                other = rank;
            } else {
                beforeValue = sc[i].a + sc[i].b;
                rank = i + 1 - skipCnt;
                other = i + 1 - skipCnt;
            }
            sc[i].other = other;
        }
        
        for(int i=0; i<sc.length; ++i) {
            if(!sc[i].oh) continue;
            if(!sc[i].use) return -1;
            return sc[i].other;
        }
        
        return -1;
    }
    
    static class Stat {
        public int other;
        public int a, b;
        public boolean oh;
        public boolean use;
        
        public Stat(int a, int b, boolean oh) {
            this.a = a;
            this.b = b;
            this.oh = oh;
            use = true;
        }
    }
}