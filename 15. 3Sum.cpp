#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> ansVec;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i], left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int curSum = nums[left] + nums[right];
                if (curSum == target) {
                    std::vector<int> temp {nums[i], nums[left], nums[right]};
                    ansVec.push_back(temp);

                    while (left <= right && nums[left] == temp[1]) {
                        left++;
                    }
                    while (left <= right && nums[right] == temp[2]) {
                        right--;
                    }
                } else if (curSum > target) {
                    right--;
                } else if (curSum < target) {
                    left++;
                }
            }
        }
        return ansVec;
    }
};