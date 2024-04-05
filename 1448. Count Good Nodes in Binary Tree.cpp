struct TreeNode {
       int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    //TC O(n), SC O(logn) 
private:
    int goodNodeCount = 0;
    void findGoodNode(TreeNode* root, int curMax){
        if(!root){
            return;
        }
        if(root->val >= curMax){
            goodNodeCount++;
            curMax = root->val;
        }
        findGoodNode(root->left, curMax);
        findGoodNode(root->right, curMax);
    }
public:
    int goodNodes(TreeNode* root) {
        findGoodNode(root, -1e5);
        return goodNodeCount;
    }
};