/*
Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {

    private static boolean[] chk;

    public Node cloneGraph(Node node) {
        chk = new boolean[105];
        Map<Integer, Node> nodeMap = new HashMap<>();
        Map<Integer, Node> clonedMap = new HashMap<>();
        if (node != null && node.val != 0) chk[node.val] = true;
        initMap(nodeMap, clonedMap, node);

        clonedMap.forEach((v, clonedNode) -> {
            Node originNode = nodeMap.get(v);
            List<Node> neighbors = originNode.neighbors;

            for (Node neighbor : neighbors) {
                Node clonedNeighbor = clonedMap.get(neighbor.val);
                clonedNode.neighbors.add(clonedNeighbor);
            }
        });

        return node == null ? null : clonedMap.get(node.val);
    }

    public void initMap(
        Map<Integer, Node> nodeMap,
        Map<Integer, Node> clonedMap,
        Node cur
    ) {
        if (cur == null || cur.val == 0) return;
        nodeMap.put(cur.val, cur);
        clonedMap.put(cur.val, new Node(cur.val));
        for (Node next : cur.neighbors) {
            if (chk[next.val]) continue;
            chk[next.val] = true;
            initMap(nodeMap, clonedMap, next);
        }
    }
}
