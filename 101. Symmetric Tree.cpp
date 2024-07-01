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
    bool isEqual(TreeNode* curR, TreeNode* curL){
        if(!curR && !curL){
            return true;
        }
        if(!curR || !curL){
            return false;
        }
        if(curR->val != curL->val){
            return false;
        }
        return isEqual(curR->right, curL->left) && isEqual(curR->left, curL->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isEqual(root->right, root->left);
    }
};