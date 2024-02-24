class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //TC O(n), SC O(1)
        int len = nums.size(), sum = len*(len + 1)/2;
        for(int num:nums){
            sum -= num;
        }
        return sum;
        
    }
};