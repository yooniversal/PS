class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<Integer> ret = new ArrayList<>();
        
        List<List<Integer>> e = new ArrayList<>();
        for (int i=0; i<numCourses; i++) e.add(new ArrayList<>());

        int[] inDegree = new int[numCourses];
        for (int[] p : prerequisites) {
            inDegree[p[0]]++;
            e.get(p[1]).add(p[0]);
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i=0; i<numCourses; i++) {
            if (inDegree[i] == 0) {
                q.add(i);
            }
        }

        int searchedCnt = 0;
        while (!q.isEmpty()) {
            int cur = q.poll();
            
            searchedCnt++;
            ret.add(cur);

            for (int next : e.get(cur)) {
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    q.add(next);
                }
            }
        }

        if (searchedCnt != numCourses) return new int[]{};

        int[] result = new int[ret.size()];
        for (int i=0; i<ret.size(); i++) result[i] = ret.get(i);
        return result;
    }
}
