class WordDictionary {

    Node root;

    class Node {
        Node[] next;
        boolean finish;
        
        public Node() {
            next = new Node[26];
            finish = false;
        }
    }

    public WordDictionary() {
        root = new Node();
    }

    public void addWord(String word) {
        insert(root, word, 0);
    }

    public boolean search(String word) {
        return search(root, word, 0);
    }

    private void insert(Node cur, String word, int pos) {
        if (cur == null) return;

        boolean isFinish = pos == word.length()-1;

        Node next = cur.next[(int)(word.charAt(pos) - 'a')];
        if (next == null) {
            Node newNode = new Node();
            cur.next[(int)(word.charAt(pos) - 'a')] = newNode;
            next = newNode;
            if (isFinish) newNode.finish = true;
        } else {
            if (isFinish) next.finish = true;
        }

        if (!isFinish) insert(next, word, pos+1);
    }

    private boolean search(Node cur, String word, int pos) {
        if (cur == null) return false;
        if (pos == word.length()) {
            return cur.finish;
        }

        if (word.charAt(pos) == '.') {
            for (Node next : cur.next) {
                if (next == null) continue;
                boolean result = search(next, word, pos+1);
                if (result) return true;
            }
            return false;
        }

        Node next = cur.next[(int)(word.charAt(pos) - 'a')];
        if (next == null) return false;

        return search(next, word, pos+1);
    }
}
