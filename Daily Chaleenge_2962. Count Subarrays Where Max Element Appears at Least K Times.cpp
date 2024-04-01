#include <algorithm>
#include <vector>

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int k) {
        //partial credit to lee215, TC O(n), SC O(1)
        int curMax = *std::max_element(nums.begin(), nums.end());
        int maxCount = 0, left = 0;
        long long subarrayCount = 0;
        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == curMax){
                maxCount++;
            }

            while(maxCount >= k){
                if(nums[left] == curMax){
                    maxCount--;
                }
                left++;
            }
            subarrayCount += left;
        }

        return subarrayCount;
    }
};