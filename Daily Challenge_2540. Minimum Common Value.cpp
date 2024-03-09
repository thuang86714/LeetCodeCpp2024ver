#include <vector>

class Solution {
public:
    int getCommon(std::vector<int>& nums1, std::vector<int>& nums2) {
        //TC O(n), SC O(1)
        int idx1 = 0, idx2 = 0;
        while(idx1 < nums1.size() && idx2 < nums2.size()){
            if(nums1[idx1] == nums2[idx2]){
                return nums2[idx2];
            }else if(nums1[idx1] > nums2[idx2]){
                idx2++;
            }else{
                idx1++;
            }
        }
        return -1;
    }
};