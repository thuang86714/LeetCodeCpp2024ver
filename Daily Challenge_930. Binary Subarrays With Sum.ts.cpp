#include <vector>

class Solution {
private:
    //atMostSubArray(A, S) counts the number of the subarrays of A the sum of which is at most(less than or equal to) S.
    int atMostSubArray(std::vector<int>& nums, int goal){
        if(goal < 0){
            return 0;
        }
        int left = 0, right = 0, ans = 0;
        for(; right < nums.size(); right++){
            goal -= nums[right];
            while(goal < 0){
                goal += nums[left++];
            }
            ans += right - left + 1;//Through this process, we can count the number of the subarrays.
        }
        return ans;
    }
public:
    int numSubarraysWithSum(std::vector<int>& nums, int goal) {
        //credit to lee215 and Ruolinbi, TC O(n), SC O(1)
        return atMostSubArray(nums, goal) - atMostSubArray(nums, goal - 1);
    }
};