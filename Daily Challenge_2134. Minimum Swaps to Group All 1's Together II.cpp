#include <vector>

class Solution {
public:
    int minSwaps(std::vector<int>& nums) {
        // TC O(n), SC O(1), credit to votrubac; Sliding window, ones is going
        // to be the window size
        int ones = 0;
        const int n = nums.size();
        for (const int& num : nums) {
            ones += num;
        }
        int curOne = 0, res = n, j = 0;
        for (int i = 0; i < n; i++) {
            while (j - i < ones) {
                curOne += nums[j % n];
                j++;
            }
            res = std::min(res, ones - curOne); // diff show how many 0 are there
            curOne -= nums[i];
        }
        return res;
    }
};