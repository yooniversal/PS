/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct Node {
        int parent, left, right, depth;
    };

    Node a[100005];
    vector<int> leaf;
    int root_val, end_val;
    int cache[100005];

    void init(TreeNode* cur, int parent) {
        end_val = max(end_val, cur->val);
        int l = cur->left != nullptr ? cur->left->val : -1;
        int r = cur->right != nullptr ? cur->right->val : -1;
        if (l == -1 && r == -1) leaf.push_back(cur->val);

        a[cur->val] = {parent, l, r, 0};
        if (cur->left != nullptr) init(cur->left, cur->val);
        if (cur->right != nullptr) init(cur->right, cur->val);
    }

    void init_depth(int cur, int depth) {
        a[cur].depth = max(a[cur].depth, depth);
        if (cur != root_val)init_depth(a[cur].parent, depth + 1);
    }

    int get_root_depth(int target, int prev, int cur, int depth) {
        if (cur == -1) return depth;

        int left = a[cur].left;
        int right = a[cur].right;
        int left_depth = 0;
        if (a[cur].left == target || a[cur].left == -1) {
            left_depth = -1;
        } else if (a[cur].left == prev) {
            left_depth = depth;
        } else {
            left_depth = a[left].depth;
        }
        int right_depth = 0;
        if (a[cur].right == target || a[cur].right == -1) {
            right_depth = -1;
        } else if (a[cur].right == prev) {
            right_depth = depth;
        } else {
            right_depth = a[right].depth;
        }

        depth = max(left_depth, right_depth) + 1;

        return get_root_depth(target, cur, a[cur].parent, depth);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ret;

        root_val = root->val;
        init(root, -1);
        for (auto& l : leaf) {
            init_depth(l, 0);
        }

        for (auto& target : queries) {
            if (cache[target] == 0) {
                cache[target] = get_root_depth(target, target, a[target].parent, 0);
            }
            ret.push_back(cache[target]);
        }
        
        return ret;
    }
};