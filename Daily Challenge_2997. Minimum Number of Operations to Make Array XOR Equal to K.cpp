#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        //credit to lee215, TC O(logn), SC O(1)
        for(int &num:nums){
            k ^= num;
        }
        return __builtin_popcount(k);
    }
};