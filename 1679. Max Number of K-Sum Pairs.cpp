class Solution {
#include <vector>
#include <unordered_map>

public:
    int maxOperations(std::vector<int>& nums, int k) {
        //TC O(n), SC O(n)
        std::unordered_map<int, int> dict;
        int ans = 0;
        for(int &num:nums){
            dict[num]++;
        }
        for(int &num:nums){
            if(dict[num]){
                dict[num]--;
                if(dict[k - num]){
                    ans++;
                    dict[k - num]--;
                }else{
                    dict[num]++;
                }
            }
        }
        return ans;
    }
};