class Solution {

    private int[] dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    Map<Integer, Set<Integer>> obMap;

    public int robotSim(int[] commands, int[][] obstacles) {
        int ret = 0;

        int d = 0;
        int x = 0, y = 0;

        obMap = new HashMap<>();
        for (int[] ob : obstacles) {
            Set<Integer> obSet = obMap.getOrDefault(ob[0], new HashSet<>());
            obSet.add(ob[1]);
            obMap.put(ob[0], obSet);
        }

        for (int com : commands) {
            if (com == -1) d = (d+1) % 4;
            else if (com == -2) d = (d-1 + 4) % 4;
            else {
                for (int i=0; i<com; i++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (obMap.getOrDefault(nx, Collections.emptySet()).contains(ny)) break;
                    x = nx;
                    y = ny;

                    ret = Math.max(ret, x*x + y*y);
                }
            }
        }

        return ret;
    }
}
