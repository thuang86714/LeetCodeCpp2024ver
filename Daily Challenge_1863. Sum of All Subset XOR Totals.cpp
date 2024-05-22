#include <vector>

class Solution {
private:
    int sum = 0;
    void findEachSubsetSum(const std::vector<int>& nums, int idx, int curXorVal){
        if(idx == nums.size()){
            sum += curXorVal;
            return;
        }
        
        findEachSubsetSum(nums, idx + 1, curXorVal ^ nums[idx]);
        findEachSubsetSum(nums, idx + 1, curXorVal);
    }
public:
    int subsetXORSum(std::vector<int>& nums) {
        //TC O(2^n), SC O(n)
        findEachSubsetSum(nums, 0, 0);
        return sum;
    }
};