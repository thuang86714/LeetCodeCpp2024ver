struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

#include <vector>
class Solution {
    //TC O(n), SC O(n)
private:
    std::vector<TreeNode*> treeNodePtrVec;
    void collectAllNodes(TreeNode* node) {
        if (!node) {
            return;
        }
        collectAllNodes(node->left);
        treeNodePtrVec.push_back(node);
        collectAllNodes(node->right);
    }
    TreeNode* buildTree(int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = (end - start) / 2 + start;
        TreeNode* curNode = treeNodePtrVec[mid];
        curNode->left = buildTree(start, mid - 1);
        curNode->right = buildTree(mid + 1, end);
        return curNode;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        collectAllNodes(root);
        int totalNodeCount = treeNodePtrVec.size();
        return buildTree(0, totalNodeCount - 1);
    }
};