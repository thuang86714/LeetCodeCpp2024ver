#include <vector>
#include <algorithm>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        //credit to makuiyu and jianchao-li, V0idk. TC O(n), SC O(1)
        int n = nums.size(), i = 0;
        while (i < n){
            if (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                std::swap(nums[i], nums[nums[i]-1]);
            }else{
                i++;
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        return n + 1;
    }
};