class MagicDictionary {

    Node root;

    class Node {
        Node[] next;
        boolean finish;
        
        public Node() {
            next = new Node[26];
            finish = false;
        }
    }

    public MagicDictionary() {
        root = new Node();
    }
    
    public void buildDict(String[] dictionary) {
        for (String d : dictionary) {
            insert(d);
        }
    }
    
    public boolean search(String searchWord) {
        return search(root, searchWord, 0, false);
    }

    private void insert(String word) {
        insert(root, word, 0);
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

    private boolean search(Node cur, String word, int pos, boolean changed) {
        if (cur == null) return false;
        if (pos == word.length()) {
            return cur.finish && changed;
        }

        Node next = cur.next[(int)(word.charAt(pos) - 'a')];
        if (next == null) {
            if (!changed) {
                for (int i=0; i<26; i++) {
                    if (cur.next[i] == null) continue;
                    boolean changedResult = search(cur.next[i], word, pos+1, true);
                    if (changedResult) return true;
                }
            }
        }

        boolean ret = search(next, word, pos+1, changed);
        if (ret) return true;

        if (!changed) {
            for (int i=0; i<26; i++) {
                if (i == (int)(word.charAt(pos) - 'a')) continue;
                if (cur.next[i] == null) continue;
                ret = search(cur.next[i], word, pos+1, true);
                if (ret) return true;
            }
        }

        return false;
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dictionary);
 * boolean param_2 = obj.search(searchWord);
 */
