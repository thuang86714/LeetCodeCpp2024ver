#include <vector>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if(n < 3){
            if(n == 0){
                return 0;
            }else{
                return 1;
            }
        }
        int oneStep = 1, twoStep = 1, threeStep = 0, cur = 0;
        for(int i = 3; i <= n; i++){
            cur = oneStep + twoStep + threeStep;
            threeStep = twoStep;
            twoStep = oneStep;
            oneStep = cur;
        }
        return cur;
    }
};

class Solution {
public:
    int tribonacci(int n) {
        if(n < 3){
            if(n == 0){
                return 0;
            }else{
                return 1;
            }
        }
        vector<int> memo(n + 1);
        memo[0] = 0, memo[1] = 1, memo[2] = 1;
        for(int i = 3; i <= n; i++){
            memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
        }
        return memo.back();
    }
};