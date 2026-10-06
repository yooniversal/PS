class LRUCache {

    Map<Integer, Node> cache;
    Node head;
    Node tail;
    int currentSize;
    int capacity;

    public LRUCache(int capacity) {
        cache = new HashMap<>();
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head.next = tail;
        tail.prev = head;
        this.capacity = capacity;
    }
    
    public int get(int key) {
        Node node = cache.get(key);

        if (node == null) return -1;

        moveToLast(node);

        return node.value;
    }
    
    public void put(int key, int value) {
        Node node = cache.get(key);

        if (node != null) {
            node.value = value;
            moveToLast(node);
            return;
        }

        node = new Node(key, value);

        if (currentSize == capacity) {
            Node removeTarget = head.next;
            cache.remove(removeTarget.key);
            remove(removeTarget);

            currentSize--;
        }
        
        addToLast(node);
        cache.put(key, node);

        currentSize++;
    }

    private void moveToLast(Node node) {
        remove(node);
        addToLast(node);
    }

    private void remove(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    private void addToLast(Node node) {
        Node last = tail.prev;
        last.next = node;
        node.prev = last;

        tail.prev = node;
        node.next = tail;
    }

    class Node {
        int key, value;
        Node prev, next;

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public String toString() {
            return Integer.toString(value);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
