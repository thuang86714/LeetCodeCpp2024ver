#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int idx1 = m - 1, idx2 = n - 1, curIdx = m + n - 1;

        for (; idx1 >= 0 && idx2 >= 0 && curIdx >= 0; curIdx--) {
            if (nums1[idx1] > nums2[idx2]) {
                nums1[curIdx] = nums1[idx1];
                idx1--;
            } else {
                nums1[curIdx] = nums2[idx2];
                idx2--;
            }
        }

        for (; idx1 >= 0 && curIdx >= 0; curIdx--) {
            nums1[curIdx] = nums1[idx1];
            idx1--;
        }

        for (; idx2 >= 0 && curIdx >= 0; curIdx--) {
            nums1[curIdx] = nums2[idx2];
            idx2--;
        }
    }
};