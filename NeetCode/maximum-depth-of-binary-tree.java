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
    public int maxDepth(TreeNode root) {
        return getDepth(root, 1);
    }

    public int getDepth(TreeNode cur, int depth) {
        if (cur == null) return depth-1;
        int leftDepth = cur.left != null ? getDepth(cur.left, depth+1) : 0;
        int rightDepth = cur.right != null ? getDepth(cur.right, depth+1) : 0;
        int ret = Math.max(depth, Math.max(leftDepth, rightDepth));
        return ret;
    }
}
