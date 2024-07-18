struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};
#include <string>
class Solution {
public:
    std::string getDirections(TreeNode* root, int startValue, int destValue) {
        std::string startPath = "", destPath = "";
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);
        while (!startPath.empty() && !destPath.empty() &&
               startPath.back() == destPath.back()) {
            startPath.pop_back();
            destPath.pop_back();
        }
        return std::string(startPath.size(), 'U') +
               std::string(destPath.rbegin(), destPath.rend());
    }

private:
    bool findPath(TreeNode* node, int value, std::string& path) {
        if (node->val == value) {
            return true;
        }

        if (node->left && findPath(node->left, value, path)) {
            path.push_back('L');
        } else if (node->right && findPath(node->right, value, path)) {
            path.push_back('R');
        }

        return !path.empty();
    }
};