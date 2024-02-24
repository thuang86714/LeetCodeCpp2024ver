#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //credit to kevinjunior, TC O(n), SC O(n)
        vector<int> ans(nums.size(), 0);
        int pPtr = 0, nPtr = 1;
        for(int num:nums){
            if(num > 0){
                ans[pPtr] = num;
                pPtr += 2;
            }else{
                ans[nPtr] = num;
                nPtr += 2;
            }
        }
        return ans;
    }
};