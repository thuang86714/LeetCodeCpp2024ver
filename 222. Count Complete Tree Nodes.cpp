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
public:
    int countNodes(TreeNode* root) {
        //TC O(logn)
        TreeNode *curL = root, *curR = root;
        int leftHeight = 0, rightHeight = 0;
        while (curL) {
            curL = curL->left;
            leftHeight++;
        }
        while (curR) {
            curR = curR->right;
            rightHeight++;
        }

        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};