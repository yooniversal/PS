class LRUCache {

    Map<Integer, Node> cache;
    Map<Integer, Node> timeMap;
    Queue<Integer> timeQueue;
    Set<Integer> aliveTimeSet;
    int globalTime = 0;
    int capacity;

    class Node {
        int key;
        int value;
        int time;

        public Node(int key, int value, int time) {
            this.key = key;
            this.value = value;
            this.time = time;
        }
    }

    public LRUCache(int capacity) {
        cache = new HashMap<>();
        timeMap = new HashMap<>();
        timeQueue = new LinkedList<>();
        aliveTimeSet = new HashSet<>();
        this.capacity = capacity;
    }
    
    public int get(int key) {
        if (!cache.containsKey(key)) return -1;
        initTime(key);
        return cache.get(key).value;
    }
    
    public void put(int key, int value) {
        if (!cache.containsKey(key)) {
            if (cache.size() == capacity) {
                // delete
                int minTime = getMinTime();

                Node removeNode = timeMap.get(minTime);
                timeMap.remove(minTime);
                aliveTimeSet.remove(minTime);
                cache.remove(removeNode.key);
            }

            // insert
            int newTime = generateTime();
            Node newNode = new Node(key, value, newTime);
            cache.put(key, newNode);
            timeMap.put(newTime, newNode);
            timeQueue.add(newTime);
            aliveTimeSet.add(newTime);
        } else {
            // update
            int newTime = generateTime();
            Node node = cache.get(key);
            node.value = value;
            timeMap.remove(node.time);
            aliveTimeSet.remove(node.time);

            node.time = newTime;
            aliveTimeSet.add(newTime);
            timeMap.put(newTime, node);
            timeQueue.add(newTime);
        }
    }

    private void initTime(int key) {
        Node node = cache.get(key);

        int beforeTime = node.time;
        timeMap.remove(beforeTime);
        aliveTimeSet.remove(beforeTime);

        node.time = generateTime();
        timeMap.put(node.time, node);

        timeQueue.add(node.time);
        aliveTimeSet.add(node.time);
    }

    private int generateTime() {
        return ++globalTime;
    }

    private int getMinTime() {
        while (!timeQueue.isEmpty()) {
            int queueMinTime = timeQueue.poll();
            if (!aliveTimeSet.contains(queueMinTime)) continue;
            return queueMinTime;
        }

        return 0;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
