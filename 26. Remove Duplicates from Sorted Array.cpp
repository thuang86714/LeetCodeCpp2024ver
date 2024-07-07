#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int count = 0;
        for (int idx = 1; idx < nums.size(); idx++) {
            if (nums[idx] == nums[idx - 1]) {
                count++;
            } else {
                nums[idx - count] = nums[idx];
            }
        }
        return nums.size() - count;
    }
};