#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        //TC O(n), SC O(1)
        if(nums.size() < 3){
            return *max_element(nums.begin(), nums.end());
        }

        int twoStep = nums[0], oneStep = max(nums[0], nums[1]), cur = 0;
        for(int i = 2; i < nums.size(); i++){
            cur = max(oneStep, twoStep + nums[i]);
            twoStep = oneStep;
            oneStep = cur;
        }
        return cur;
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        //TC O(n), SC O(n)
        if(nums.size() < 3){
            return *max_element(nums.begin(), nums.end());
        }

        vector<int> memo(nums.size());
        memo[0] = nums[0], memo[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            memo[i] = max(memo[i - 1], memo[i - 2] + nums[i]);
        }
        return memo.back();
    }
};