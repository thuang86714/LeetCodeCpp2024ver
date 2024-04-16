struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int pathCount = 0;
    void countAllValidPath(TreeNode* node, long curSum){
        if(!node){
            return;
        }

        if(node->val == curSum){
            pathCount++;
        }

        countAllValidPath(node->left, curSum - node->val);
        countAllValidPath(node->right, curSum - node->val);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            countAllValidPath(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return pathCount;
    }
};