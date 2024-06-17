#include <vector>
#include <algorithm>

class Solution {
public:
    int minIncrementForUnique(std::vector<int>& nums) {
        //TC o(nlogn), SC O(1)
        std::sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            int diff = nums[i - 1] + 1 - nums[i];
            if(diff > 0){
                count += diff;
                nums[i] += diff;
            }
        }
        return count;
    }
};