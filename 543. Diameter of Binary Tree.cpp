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
private:
    int ans = 0;
    int findDepth(TreeNode* root){
        if(!root){
            return 0;
        }
        
        int leftHeight = findDepth(root->left);
        int rightHeight = findDepth(root->right);
        ans = max(ans, 1 + leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        //DFS, TC O(n), SC O(logn)
        if(!root){
            return 0;
        }
        findDepth(root);
        return ans - 1;
    }
};