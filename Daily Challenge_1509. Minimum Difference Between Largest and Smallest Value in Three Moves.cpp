#include <vector>
#include <algorithm>
class Solution {
public:
    int minDifference(std::vector<int>& nums) {
        //credit to lee215, TC O(nlogn), SC O(1)
        int n = nums.size();
        if(n <= 4){
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        return std::min({nums[n - 1] - nums[3], nums[n - 2] - nums[2], nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
    }
};