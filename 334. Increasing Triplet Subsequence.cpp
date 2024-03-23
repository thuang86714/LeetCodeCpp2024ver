#include <vector>
#include <climits>

class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        //TC O(n), SC O(1)
        if(nums.size() < 3){
            return false;
        }
        int nums1 = INT_MAX, nums2 = INT_MAX;
        for(int &n:nums){
            if(n <= nums1){
                nums1 = n;
            }else if(n <= nums2){
                nums2 = n;
            }else{
                return true;
            }
        }
        return false;
    }
};