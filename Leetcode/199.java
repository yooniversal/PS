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

    private List<Integer> ret;

    public List<Integer> rightSideView(TreeNode root) {
        ret = new ArrayList<>();

        search(root, 0);

        return ret;
    }

    private void search(TreeNode cur, int depth) {
        if (cur == null) return;
        while (ret.size()-1 < depth) ret.add(0);
        ret.set(depth, cur.val);
        if (cur.left != null) search(cur.left, depth+1);
        if (cur.right != null) search(cur.right, depth+1);
    }
}
