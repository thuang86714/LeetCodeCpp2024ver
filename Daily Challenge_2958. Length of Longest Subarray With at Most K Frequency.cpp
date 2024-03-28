#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        //TC O(n), SC O(n)
        std::unordered_map<int, int> numCount;//<nums[i],count>
        int maxLen = 0, left = 0;
        for(int right = 0; right < nums.size(); right++){
            numCount[nums[right]]++;
            while(numCount[nums[right]] > k){
                numCount[nums[left]]--;
                left++;
            }
            maxLen = std::max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};