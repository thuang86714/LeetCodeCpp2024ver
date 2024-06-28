class Solution {
    //credit to archit91, Dynamic Programming - Memoization, TC O(n), SC O(n)
private:
    const int MOD = 1e9+7;
    int end = 0;
    int memo[1001][2]{};
    long findSolution(int idx, bool hasPreviousGap){
        if(idx > end){
            return 0;
        }
        if(idx == end){
            return !hasPreviousGap;
        }
        if(memo[idx][hasPreviousGap]){
            return memo[idx][hasPreviousGap];
        }
        if(hasPreviousGap){
            return memo[idx][hasPreviousGap] = (findSolution(idx + 1, false) + findSolution(idx + 1, true))%MOD;
        }
        return memo[idx][hasPreviousGap] = (findSolution(idx + 1, false) + findSolution(idx + 2, false) + 2*findSolution(idx + 2, true))%MOD;
    }
public:
    int numTilings(int n) {
        end = n;
        return findSolution(0, false);
    }
};

#include <vector>
class Solution {
    // credit to archit91, Dynamic Programming - Tabulation, TC O(n), SC O(n)
private:
    const int MOD = 1e9 + 7;

public:
    int numTilings(int n) {
        std::vector<std::vector<int>> memo(n + 2, std::vector<int>(2));
        memo[1] = {1, 1}, memo[2] = {2, 2};
        for (int i = 3; i <= n; i++) {
            memo[i][0] =
                (memo[i - 1][0] + memo[i - 2][0] + 2l * memo[i - 2][1]) % MOD;
            memo[i][1] = (memo[i - 1][0] + memo[i - 1][1]) % MOD;
        }
        return memo[n][0];
    }
};

class Solution {
    // credit to archit91, Dynamic Programming - Tabulation && Space-Optimized, TC O(n), SC O(n)
private:
    const int MOD = 1e9 + 7;

public:
    int numTilings(int n) {
        std::vector<std::vector<int>> memo(3, std::vector<int>(2));
        memo[1] = {1, 1}, memo[2] = {2, 2};
        for (int i = 3; i <= n; i++) {
            memo[i%3][0] =
                (memo[(i - 1)%3][0] + memo[(i - 2)%3][0] + 2l * memo[(i - 2)%3][1]) % MOD;
            memo[i%3][1] = (memo[(i - 1)%3][0] + memo[(i - 1)%3][1]) % MOD;
        }
        return memo[n%3][0];
    }
};