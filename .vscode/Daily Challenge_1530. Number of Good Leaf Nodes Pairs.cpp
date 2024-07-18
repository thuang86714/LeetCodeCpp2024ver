#include <vector>

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
private:
    int ans = 0;
    std::vector<int> findPathDFS(TreeNode* root, int distance) {
        if (!root) {
            return {};
        }
        if (!root->left && !root->right) {
            return {1};
        }

        std::vector<int> leftVec = findPathDFS(root->left, distance);
        std::vector<int> rightVec = findPathDFS(root->right, distance);

        for (const int& left : leftVec) {
            for (const int& right : rightVec) {
                if (left + right <= distance) {
                    ans++;
                }
            }
        }

        std::vector<int> result;
        for (const int& left : leftVec) {
            if (left < distance) {
                result.push_back(left + 1);
            }
        }
        for (const int& right : rightVec) {
            if (right < distance) {
                result.push_back(right + 1);
            }
        }
        return result;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        findPathDFS(root, distance);
        return ans;
    }
};