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

    private boolean ret;

    public boolean isBalanced(TreeNode root) {
        if (root == null) return true;

        ret = true;

        int dl = getDepth(root.left);
        int dr = getDepth(root.right);

        if (Math.abs(dl - dr) > 1) {
            ret = false;
        }

        return ret;
    }

    private int getDepth(TreeNode cur) {
        if (cur == null) return 0;
        int dl = getDepth(cur.left);
        int dr = getDepth(cur.right);

        if (Math.abs(dl - dr) > 1) {
            ret = false;
        }

        return Math.max(dl, dr) + 1;
    }
}
