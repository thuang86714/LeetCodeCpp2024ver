#include <vector>
#include <cmath>
class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        //can we do TC O(n)-->yes, credit to andnik and yuluairoy
        int len = nums.size() - 1, left = 0, right = len; 
        std::vector<int> ans(len + 1);
        for(; len >= 0; len--){
            if(std::abs(nums[left]) > std::abs(nums[right])){
                ans[len] = nums[left] * nums[left++];
            }else{
                ans[len] = nums[right] * nums[right--];
            }
        }
        return ans;
    }
};