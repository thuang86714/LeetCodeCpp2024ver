#include <vector>

class Solution {
public:
    bool threeConsecutiveOdds(std::vector<int>& arr) {
        int curLen = 0;
        for (int idx = 0; idx < arr.size(); idx++) {
            if (arr[idx] % 2 == 0) {
                curLen = 0;
                continue;
            }
            curLen++;
            if (curLen == 3) {
                return true;
            }
        }
        return false;
    }
};