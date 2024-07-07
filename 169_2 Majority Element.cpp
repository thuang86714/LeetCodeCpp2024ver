#include <vector>
#include <algorithm>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int mid = nums.size()/2;
        return nums[mid];
    }
};