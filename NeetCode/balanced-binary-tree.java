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

        int leftH = getHeight(root.left, 1);
        int rightH = getHeight(root.right, 1);

        if (Math.abs(leftH - rightH) > 1) ret = false;

        return ret;
    }

    private int getHeight(TreeNode cur, int depth) {
        if (cur == null) return depth-1;
        if (cur.left == null && cur.right == null) return depth;
        
        int leftH = getHeight(cur.left, depth+1);
        int rightH = getHeight(cur.right, depth+1);
        if (Math.abs(leftH - rightH) > 1) ret = false;

        return Math.max(leftH, rightH);
    }
}
