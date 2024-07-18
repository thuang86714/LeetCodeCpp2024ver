#include <unordered_map>
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
public:
    TreeNode* createBinaryTree(std::vector<std::vector<int>>& descriptions) {
        std::unordered_map<int, std::pair<TreeNode*, int>> valTreeNodeMap;
        TreeNode* ans;
        for (const auto& description : descriptions) {
            TreeNode* curRoot;
            if (!valTreeNodeMap.count(description[0])) {
                valTreeNodeMap[description[0]] = {new TreeNode(description[0]),
                                                  0};
            }
            curRoot = valTreeNodeMap[description[0]].first;

            if (!valTreeNodeMap.count(description[1])) {
                valTreeNodeMap[description[1]] = {new TreeNode(description[1]),
                                                  1};
            } else {
                TreeNode* temp = valTreeNodeMap[description[1]].first;
                valTreeNodeMap[description[1]] = {temp, 1};
            }

            if (description[2] == 1) {
                curRoot->left = valTreeNodeMap[description[1]].first;
            } else {
                curRoot->right = valTreeNodeMap[description[1]].first;
            }
        }

        for (const auto& node : valTreeNodeMap) {
            if (node.second.second == 0) {
                ans = node.second.first;
            }
        }
        return ans;
    }
};