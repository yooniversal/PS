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
    public TreeNode invertTree(TreeNode root) {
        invert(root);
        return root;
    }

    public void invert(TreeNode cur) {
        if (cur == null) return;
        if (cur.left == null && cur.right == null) return;
        if (cur.left == null) {
            cur.left = cur.right;
            cur.right = null;
            invert(cur.left);
        } else if (cur.right == null) {
            cur.right = cur.left;
            cur.left = null;
            invert(cur.right);
        } else {
            TreeNode tmp = cur.left;
            cur.left = cur.right;
            cur.right = tmp;
            invert(cur.left);
            invert(cur.right);
        }
    }
}
