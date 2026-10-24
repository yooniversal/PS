public boolean possibleBipartition(int n, int[][] dislikes) {
    int[] color = new int[n+1];
    List<List<Integer>> e = new ArrayList<>();

    for (int i=0; i<=n; i++) {
        e.add(new ArrayList<>());
    }

    for (int[] d : dislikes) {
        e.get(d[0]).add(d[1]);
        e.get(d[1]).add(d[0]);
    }

    for (int i=1; i<=n; i++) {
        if (color[i] == 0) {
            color[i] = 1;
            boolean result = DFS(i, color, e);

            if (!result) return false;
        }
    }

    return true;
}

private boolean DFS(int cur,
                int[] color,
                List<List<Integer>> e) {
    
    int currentColor = color[cur];
    for (int next : e.get(cur)) {
        if (color[next] == 0) {
            color[next] = currentColor == 1 ? 2 : 1;
            boolean result = DFS(next, color, e);

            if (!result) return false;
            
            continue;
        }

        if (color[next] == currentColor) {
            return false;
        }
    }

    return true;
}