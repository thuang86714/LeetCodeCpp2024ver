struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        //TC O(n), SC O(height of tree)
        if(!root){
            return false;
        }
        if(root->val > 1){
            if(root->val == 2){
                return evaluateTree(root->left) or evaluateTree(root->right);
            }
            return evaluateTree(root->left) and evaluateTree(root->right);
        }
        return root->val > 0;
    }
};