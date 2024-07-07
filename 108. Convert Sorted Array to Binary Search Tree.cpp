#include <vector>

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        //could use two pointer to optimize memory complexity
        if (nums.size() == 0) {
            return nullptr;
        }

        int mid = (nums.size()) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        std::vector<int> leftVec, rightVec;
        for (int i = 0; i < mid; i++) {
            leftVec.push_back(nums[i]);
            if (mid + 1 + i < nums.size()) {
                rightVec.push_back(nums[mid + 1 + i]);
            }
        }
        root->left = sortedArrayToBST(leftVec);
        root->right = sortedArrayToBST(rightVec);
        return root;
    }
};