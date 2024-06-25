#include <vector>

class Solution {
private:
    int atMostCount(const std::vector<int>& nums, int k){
        int res = 0, left = 0;
        for(int right = 0; right < nums.size(); right++){
            k -= nums[right]%2;
            while(k < 0 && left < nums.size()){
                k += nums[left]%2;
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        return atMostCount(nums, k) - atMostCount(nums, k - 1);
    }
};