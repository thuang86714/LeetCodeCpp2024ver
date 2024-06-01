#include <vector>
#include <algorithm>
#include <functional>

class Solution {
public:
    int specialArray(std::vector<int>& nums) {
        //TC O(nlogn), SC O(1)
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        int left = 1, right = nums.size() - 1, mid = 0;;
        if (nums[nums.size() - 1] > nums.size()){ 
            return nums.size();
        }
        if (nums[0] == 0){
            return -1;
        }
        while(left <= right){
            mid = left + (right - left)/2;
            if(nums[mid] > mid){
                left = mid + 1;
            }else if(nums[mid] < mid){
                right = mid - 1;
            }else{
                return -1;
            }
        }
        return nums[mid] > mid ? mid + 1: mid;
    }
};