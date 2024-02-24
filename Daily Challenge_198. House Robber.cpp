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