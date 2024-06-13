#include <vector>

class Solution {
public:
    int minimizeArrayValue(std::vector<int>& nums) {
        //credit to lee215, TC O(n), SC O(1)
        /*
        The ceil average with sum of i + 1 number:
        ceil(double(sum) / (i + 1))

        We can also do integer division:
        (sum + i) / (i + 1)
        */
        long sum = 0, res = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            res = std::max(res, (sum + i)/(i + 1));
        }
        return res;
    }
};