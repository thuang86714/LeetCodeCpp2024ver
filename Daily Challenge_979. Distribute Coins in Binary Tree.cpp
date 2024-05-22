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
    int moves = 0;
    int countMoves(TreeNode *node){
        //DFS, TC O(n), SC O(height of tree)
        if(!node){
            return 0;
        }
        int leftCount = countMoves(node->left);
        int rightCount = countMoves(node->right);
        moves += std::abs(leftCount) + std::abs(rightCount);
        return node->val + leftCount + rightCount - 1;
    }

public:
    int distributeCoins(TreeNode* root) {
        countMoves(root);
        return moves;
    }
};