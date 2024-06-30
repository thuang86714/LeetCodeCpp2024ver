#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        //two pointer, TC O(n), SC O(1)
        int left = 0, right = numbers.size() - 1;
        while(left < right){
            int curSum = numbers[left] + numbers[right];
            if(curSum == target){
                return {left + 1, right + 1};
            }else if(curSum < target){
                left++;
            }else if(curSum > target){
                right--;
            }
        }
        return {-1, -1};
    }
};