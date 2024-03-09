#include <vector>
#include <algorithm>

class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        //TC O(n), SC O(1)
        std::vector<int> countTracker(101, 0);
        for(int &num:nums){
            countTracker[num]++;
        }
        int maxCount = *std::max_element(countTracker.begin(), countTracker.end());
        int res = 0;
        for(int &count:countTracker){
            if(count == maxCount){
                res += maxCount;
            }
        }
        return res;
    }
};