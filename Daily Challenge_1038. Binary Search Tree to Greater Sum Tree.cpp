struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {
private:
    int collectSum(TreeNode* node, int cur) {
        // TC O(n), SC O(height of tree)
        if (!node) {
            return cur;
        }
        node->val += collectSum(node->right, cur);
        return collectSum(node->left, node->val);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        collectSum(root, 0);
        return root;
    }
};