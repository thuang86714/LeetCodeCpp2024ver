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
    int findSum(TreeNode* node, int sum) {
        sum = sum * 10 + node->val;
        int ans = 0;
        if (!node->left && !node->right) {
            return sum;
        }
        if (node->left) {
            ans += findSum(node->left, sum);
        }
        if (node->right) {
            ans += findSum(node->right, sum);
        }
        return ans;
    }

public:
    int sumNumbers(TreeNode* root) {
        return findSum(root, 0);
    }
};