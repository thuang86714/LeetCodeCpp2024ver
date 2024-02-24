#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        //credit to alexander, TC O(n), SC O(1)
        /*
        If we sort all the numbers into buckets indexed by these numbers, this is essentially asking you to repetitively take an bucket while giving up the 2 buckets next to it. (the range of these numbers is [1, 10000]
        */
        int n = *max_element(nums.begin(), nums.end());//given
        vector<int> val(n + 1, 0);
        for(int num:nums){
            val[num] += num;
        }

        int take = 0, skip = 0;
        for(int i = 0; i <= n; i++){
            int temp = take;
            take = skip + val[i];
            skip = max(skip, temp);
        }
        return max(skip, take);
    }
};