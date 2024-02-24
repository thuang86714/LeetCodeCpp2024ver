#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        //TC O(n), SC O(1)-->space optimized
        if(n <= 1){
            return n;
        }
        int oneStep = 1, twoStep = 0, cur;
        for(int i = 2; i <= n; i++){
            cur = oneStep + twoStep;
            twoStep = oneStep;
            oneStep = cur;
        }
        return cur;
    }
};


class Solution {
public:
    int fib(int n) {
        //TC O(n), SC O(n)
        if(n <= 1){
            return n;
        }
        vector<int> memo(n + 1);
        memo[0] = 0, memo[1] = 1;
        for(int i = 2; i <= n; i++){
            memo[i] = memo[i - 1] + memo[i - 2];
        }
        return memo.back();
    }
};