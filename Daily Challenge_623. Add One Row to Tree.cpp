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
    void addNewNode(TreeNode* node, int val, int depth, int curDepth){
        if(!node){
            return;
        }
        if(curDepth < depth - 1){
            addNewNode(node->left, val, depth, curDepth + 1);
            addNewNode(node->right, val, depth, curDepth + 1);
            return;
        }

        TreeNode *oldLeftPtr = node->left, *oldRightPtr = node->right;
        TreeNode *newLeftPtr = new TreeNode(val), *newRightPtr =new TreeNode(val);
        newLeftPtr->left = oldLeftPtr;
        newRightPtr->right = oldRightPtr;
        node->left = newLeftPtr, node->right = newRightPtr;
        return;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        /*
	    The function would be called for every node in the binary tree up to depth - 1. If the tree is a complete binary tree, each level doubles the number of nodes from the previous level. 
	    The number of calls, therefore, in the worst case, grows exponentially with the height of the tree.
	    TC O(2^(d - 1)), SC O(d)
	    */
        if(depth == 1){
            TreeNode *newRoot =new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        addNewNode(root, val, depth, 1);
        return root;
    }
};