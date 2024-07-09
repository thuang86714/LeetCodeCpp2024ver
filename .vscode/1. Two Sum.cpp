#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int curTarget = target - nums[i];
            if (numMap.count(curTarget) && i != numMap[curTarget]) {
                return {i, numMap[curTarget]};
            }
        }
        return {-1, -1};
    }
};