class LFUCache {

    Map<Integer, Node> cache;
    Map<Integer, DoublyLinkedList> countMap;
    int minFreq;
    int capacity;

    class Node {
        int key, value, count;
        Node prev, next;
 
        public Node(int key, int value) {
            this.key = key;
            this.value = value;
            this.count = 1;
        }

        public void disconnect() {
            this.prev.next = next;
            this.next.prev = prev;
        }

        public void moveNextCount() {
            disconnect();

            DoublyLinkedList prevLinkedList = countMap.get(count);
            if (prevLinkedList.isEmpty() && minFreq == count) minFreq++;

            count++;

            DoublyLinkedList nextLinkedList = countMap.getOrDefault(count, new DoublyLinkedList());
            addOnLinkedList(nextLinkedList);

            countMap.put(count, nextLinkedList);
        }

        public void addOnLinkedList(DoublyLinkedList linkedList) {
            this.prev = linkedList.tail.prev;
            this.next = linkedList.tail;

            linkedList.tail.prev.next = this;
            linkedList.tail.prev = this;
        }

        public void remove() {
            disconnect();
            cache.remove(key);
        }
    }

    class DoublyLinkedList {
        Node head, tail;

        public DoublyLinkedList() {
            this.head = new Node(0, 0);
            this.tail = new Node(0, 0);

            this.head.next = tail;
            this.tail.prev = head;
        }

        public boolean isEmpty() {
            return head.next == tail;
        }
    }

    public LFUCache(int capacity) {
        cache = new HashMap<>();
        countMap = new HashMap<>();
        this.capacity = capacity;
    }
    
    public int get(int key) {
        Node node = cache.get(key);
        if (node == null) return -1;

        node.moveNextCount();
        return node.value;
    }
    
    public void put(int key, int value) {
        Node node = cache.get(key);

        if (node != null) {
            node.value = value;
            node.moveNextCount();
        } else {
            // capacity 체크
            if (cache.size() == capacity) {
                DoublyLinkedList linkedList = countMap.get(minFreq);
                Node removeNode = linkedList.head.next;
                removeNode.remove();
            }

            // 추가
            node = new Node(key, value);
            cache.put(key, node);

            DoublyLinkedList linkedList = countMap.getOrDefault(node.count, new DoublyLinkedList());
            node.addOnLinkedList(linkedList);
            countMap.put(node.count, linkedList);

            minFreq = 1;
        }
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
