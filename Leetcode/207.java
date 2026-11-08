class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] inDegree = new int[numCourses];
        List<List<Integer>> e = new ArrayList<>();
        for (int i=0; i<numCourses; i++) e.add(new ArrayList<>());

        for (int[] p : prerequisites) {
            int v = p[1], u = p[0];
            inDegree[v]++;
            e.get(u).add(v);
        }

        Queue<Integer> q = new LinkedList<>();

        for (int i=0; i<numCourses; i++) {
            if (inDegree[i] == 0) {
                q.add(i);
            }
        }

        boolean[] visited = new boolean[numCourses];
        int visitedCnt = 0;
        while (!q.isEmpty()) {
            int cur = q.poll();
            if (visited[cur]) continue;

            visited[cur] = true;
            visitedCnt++;

            for (int next : e.get(cur)) {
                inDegree[next]--;
                if (inDegree[next] == 0 && !visited[next]) {
                    q.add(next);
                }
            }
        }

        return visitedCnt == numCourses;
    }
}
