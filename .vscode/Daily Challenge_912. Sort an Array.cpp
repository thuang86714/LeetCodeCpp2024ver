#include <vector>

class Solution {
private:
    std::vector<int> merge(std::vector<int>& nums1, std::vector<int>& nums2){
        std::vector<int> result;
        int idx1 = 0, idx2 = 0;
        while(idx1 < nums1.size() && idx2 < nums2.size()){
            if(nums1[idx1] > nums2[idx2]){
                result.push_back(nums2[idx2]);
                idx2++;
            }else{
                result.push_back(nums1[idx1]);
                idx1++;
            }
        }

        while(idx1 < nums1.size()){
            result.push_back(nums1[idx1]);
            idx1++;
        }

        while(idx2 < nums2.size()){
            result.push_back(nums2[idx2]);
            idx2++;
        }
        return result;
    }
    std::vector<int> mergeSort(std::vector<int>& nums){
        if(nums.size() == 1){
            return nums;
        }

        int mid = nums.size()/2;
        std::vector<int> nums1(nums.begin(), nums.begin() + mid);
        std::vector<int> nums2(nums.begin() + mid, nums.end());
        std::vector<int> nums1Sorted = mergeSort(nums1);
        std::vector<int> nums2Sorted = mergeSort(nums2);
        return merge(nums1Sorted, nums2Sorted);
    }
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        return mergeSort(nums);
    }
};