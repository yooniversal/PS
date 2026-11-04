class LUPrefix {
    boolean[] visited;
    int lastUpdatedVideo = 0;

    public LUPrefix(int n) {
        visited = new boolean[n+1];
        visited[0] = true;
    }

    public void upload(int video) {
        visited[video] = true;

        while (lastUpdatedVideo + 1 < visited.length && visited[lastUpdatedVideo + 1]) {
            lastUpdatedVideo++;
        }
    }

    public int longest() {
        return lastUpdatedVideo;
    }
}
