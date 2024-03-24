#include <vector>

class Solution {
public:
    std::vector<int> countBits(int n) {
        /*
        credit to fengcc, TC O(n), SC O(1)
        i&(i-1) drops the lowest set bit. 
        For example: i = 14, its binary representation is 1110, 
        so i-1 is 1101, i&(i-1) = 1100, 
        the number of "1" in its binary representation decrease one, 
        so ret[i] = ret[i&(i-1)] + 1.
        */
        std::vector<int> ans(n + 1, 0);
        for(int i = 1; i <= n; i++){
            ans[i] = ans[i&(i - 1)] + 1;
        }
        return ans;
    }
};