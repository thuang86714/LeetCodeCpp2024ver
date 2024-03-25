#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        if(!nums.size()){
            return {};
        }
        //TC O(n), SC O(1), credit to suman_buie
        std::vector<int> ans;
        for(int &num:nums){
            if(nums[std::abs(num) - 1] < 0){//this mean we have visited this num before
                ans.push_back(std::abs(num));
            }
            nums[std::abs(num) - 1] = -nums[std::abs(num) - 1];
        }
        return ans;
    }
};