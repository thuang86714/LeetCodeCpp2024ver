#include <vector>
#include <unordered_set>

class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        //TC O(n), SC O(n)
        std::unordered_set<int> negativeNumSet;
        int ans = -1;
        for(int num:nums){
            if(num < 0){
                negativeNumSet.insert(num);
            }
        }
        for(int num:nums){
            if(num < 0){
                continue;
            }
            if(negativeNumSet.count(-1*num)){
                ans = std::max(ans, num);
            }
        }
        return ans;
    }
};

#include <algorithm>
class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        //TC O(nlogn), SC O(1), sorting + 2 ptr
        std::sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while(left < right){
            if(nums[left] + nums[right] == 0){
                return nums[right];
            }else if(nums[left] + nums[right] < 0){
                left++;
            }else{
                right--;
            }
        }
        return -1;
    }
};