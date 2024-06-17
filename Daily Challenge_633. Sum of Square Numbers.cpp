#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        //TC O(c^(1/2)), SC O(1)
        long left = 0, right = std::sqrt(c);
        while(left <= right){
            long long curSum = left*left + right*right;
            if(curSum == c){
                return true;
            }else if(curSum > c){
                right--;
            }else{
                left++;
            }
        }
        return false;
    }
};