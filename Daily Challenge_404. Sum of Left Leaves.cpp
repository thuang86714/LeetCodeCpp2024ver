#include <queue>

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
    int sumOfLeftLeaves(TreeNode* root) {
        //BFS, TC O(n), SC O(n)
        std::queue<std::pair<TreeNode*, bool>> nodeQueue;
        nodeQueue.push({root, false});
        int sum = 0;
        while(!nodeQueue.empty()){
            auto [curNode, isLeft] = nodeQueue.front();
            nodeQueue.pop();
            if(curNode->right){
                nodeQueue.push({curNode->right, false});
            }
            if(curNode->left){
                nodeQueue.push({curNode->left, true});
            }
            if(!curNode->right && !curNode->left && isLeft){
                sum += curNode->val;
            }
        }
        return sum;
    }
};



class Solution {
private:
    int sum = 0;
    void findAllLeft(TreeNode* node, bool isLeft){
        //DFS, TC O(n), SC O(height)
        if(!node){
            return;
        }

        if(!node->left && !node->right && isLeft){
            sum += node->val;
            return;
        }

        findAllLeft(node->right, false);
        findAllLeft(node->left, true);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        findAllLeft(root, false);
        return sum;
    }
};