#include <vector>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0, ans = nums.size() + 1, curSum = 0;
        for(int right = 0; right < nums.size(); right++){
            curSum += nums[right];
            while(left <= right && curSum >= target){
                ans = std::min(ans, right - left + 1);
                curSum -= nums[left];
                left++;
            }
        }
        if(ans == nums.size() + 1){
            return 0;
        }
        return ans;
    }
};

/*
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //credit to jianchao-li, TC O(nlogn)
        int n = nums.size(), len = INT_MAX;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = n; i >= 0 && sums[i] >= s; i--) {
            int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
            len = min(len, i - j + 1);
        }
        return len == INT_MAX ? 0 : len;
    }
};
*/