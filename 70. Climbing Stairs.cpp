#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        //TC O(n), SC O(1)-->Space optimized
        if(n < 3){
            return n;
        }
        int oneStep = 2, twoStep = 1, cur = 0;
        for(int i = 3; i <= n; i++){
            cur = oneStep + twoStep;
            twoStep = oneStep;
            oneStep = cur;
        }
        return cur;
    }
};


class Solution {
public:
    int climbStairs(int n) {
        //TC O(n), SC O(n)
        if(n < 3){
            return n;
        }
        vector<int> memo(n + 1);
        memo[0] = 0, memo[1] = 1, memo[2] = 2;
        for(int i = 3; i <= n; i++){
            //Each time you can either climb 1 or 2 steps
            memo[i] = memo[i - 1] + memo[i - 2];
        }
        return memo.back();
    }
};