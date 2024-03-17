#include <queue>
#include <math>

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
    int curMax = INT_MIN;
    int maxLevel = 1;
public:
    int maxLevelSum(TreeNode* root) {
        //BFS, TC O(n), SC O(n)
        std::queue<TreeNode*> toVisit;
        toVisit.push(root);
        int curLevel = 1; 
        while(!toVisit.empty()){
            int curSize = toVisit.size();
            int curSum = 0;
            for(int i = 0; i < curSize; i++){
                auto node = toVisit.front();
                toVisit.pop();
                if(node->left){
                    toVisit.push(node->left);
                }
                if(node->right){
                    toVisit.push(node->right);
                }
                curSum += node->val;
            }
            if(curSum > curMax){
                curMax = curSum;
                maxLevel = curLevel;
            }
            curLevel++;
        }
        return maxLevel;
    }
};