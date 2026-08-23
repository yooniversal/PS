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

    public boolean hasPathSum(TreeNode root, int targetSum) {
        ret = new ArrayList<>();
        process(root, new ArrayList<>(), 0, targetSum);
        return !ret.isEmpty();
    }

    private void process(TreeNode root, List<Integer> cur, int sum, int targetSum) {
        if (root == null) return;
        if (!ret.isEmpty()) return;

        cur.add(root.val);

        if (root.left == null && root.right == null && (sum + root.val == targetSum)) {
            ret.add(new ArrayList<>(cur));
            cur.remove(cur.size()-1);
            return;
        }

        if (root.left != null) process(root.left, cur, sum + root.val, targetSum);
        if (root.right != null) process(root.right, cur, sum + root.val, targetSum);

        cur.remove(cur.size()-1);
    }
}
