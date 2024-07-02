#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1,
                               std::vector<int>& nums2) {
        if (nums2.size() > nums1.size()) {
            return intersect(nums2, nums1);
        }
        // TC O(n + m), SC O(min(m, n))
        std::unordered_map<int, int> numCountMap;
        for (const int& num : nums1) {
            numCountMap[num]++;
        }

        std::vector<int> ansVec;
        for (const int& num : nums2) {
            if (numCountMap[num] > 0) {
                ansVec.push_back(num);
                numCountMap[num]--;
            }
        }
        return ansVec;
    }
};