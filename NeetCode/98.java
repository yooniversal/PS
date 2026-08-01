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
    public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        return search(root, null, null);
    }

    private boolean search(TreeNode cur, Integer minVal, Integer maxVal) {
        if (cur == null) return true;
        if (minVal != null && minVal >= cur.val) return false;
        if (maxVal != null && cur.val >= maxVal) return false;
        if (cur.left != null && cur.left.val >= cur.val) return false;
        if (cur.right != null && cur.val >= cur.right.val) return false;
        return search(cur.left, minVal, cur.val) && search(cur.right, cur.val, maxVal);
    }
}
