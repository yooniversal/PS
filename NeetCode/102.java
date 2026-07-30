/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    private List<List<Integer>> ret;

    public List<List<Integer>> levelOrder(TreeNode root) {
        ret = new ArrayList<>();

        DFS(root, 1);

        return ret;
    }

    public void DFS(TreeNode cur, int depth) {
        if (cur == null) return;

        while (ret.size() < depth) ret.add(new ArrayList<>());
        ret.get(depth-1).add(cur.val);

        if (cur.left != null) DFS(cur.left, depth+1);
        if (cur.right != null) DFS(cur.right, depth+1);
    }
}
