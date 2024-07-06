#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};


class Solution {
public:
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::queue<TreeNode*> toVisitQueue;
        toVisitQueue.push(root);
        std::vector<double> ansVec;
        while (!toVisitQueue.empty()) {
            double curSum = 0.0;
            int curCount = toVisitQueue.size();
            double curSize = double(curCount);
            while (curCount) {
                TreeNode* curNode = toVisitQueue.front();
                toVisitQueue.pop();
                curSum += curNode->val;
                if (curNode->left) {
                    toVisitQueue.push(curNode->left);
                }
                if (curNode->right) {
                    toVisitQueue.push(curNode->right);
                }
                curCount--;
            }
            ansVec.push_back(double(curSum / curSize));
        }
        return ansVec;
    }
};