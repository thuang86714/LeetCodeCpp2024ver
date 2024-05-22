#include <algorithm>
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
    int maxStep = 0;
    void findMaxLength(TreeNode* root, bool isLeft, int step){
        if(!root){
            return;
        }
        maxStep = std::max(maxStep, step);
        if(isLeft){
            findMaxLength(root->left, false, step + 1);// keep going from root to left
            findMaxLength(root->right, true, 1);// restart going from root to right
        }else{
            findMaxLength(root->right, true, step + 1);// keep going from root to left
            findMaxLength(root->left, false, 1);// restart going from root to right
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        //credit to hiepit, TC O(n), SC O(height of tree)
        findMaxLength(root, true, 0);
        findMaxLength(root, false, 0);
        return maxStep;
    }
};