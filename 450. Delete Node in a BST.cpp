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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //TC O(n), SC O(logn)
        if(!root){
            return root;
        }
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }else{
            if(!root->left && !root->right){
                return nullptr;
            }
            if(!root->left || !root->right){
                if(root->left){
                    return root->left;
                }else{
                    return root->right;
                }
            }

            TreeNode* temp = root->left;
            while(temp->right){
                temp = temp->right;
            }
            root->val = temp->val;
            root->left = deleteNode(root->left, temp->val);
        }
        return root;
    }
};