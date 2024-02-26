#include <vector>

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
    std::vector<int> leafVector1, leafVector2;
    void traverseAllLeaves(TreeNode* root, std::vector<int> &leaves){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            leaves.push_back(root->val);
            return;
        }
        traverseAllLeaves(root->left, leaves);
        traverseAllLeaves(root->right, leaves);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        traverseAllLeaves(root1, leafVector1);
        traverseAllLeaves(root2, leafVector2);
        return leafVector1 == leafVector2;
    }
};