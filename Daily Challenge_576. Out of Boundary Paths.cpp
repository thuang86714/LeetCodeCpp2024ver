#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m; this->n = n;
        memset(memo, -1, sizeof(memo));
        return dp(startRow, startColumn, maxMove);
    }
private:
    //credit to hiepit, TC O(m * n * maxMove * 4), SC O(m * n * maxMove)
    int m, n;
    int memo[50][50][51];
    int DIR[5] = {0, 1, 0, -1, 0};
    int dp(int r, int c, int maxMove) {
        if (r < 0 || r == m || c < 0 || c == n) return 1; // Out of bound -> Count 1 way
        if (maxMove == 0) return 0;
        if (memo[r][c][maxMove] != -1) return memo[r][c][maxMove];
        int ans = 0;
        for (int i = 0; i < 4; ++i)
            ans = (ans + dp(r + DIR[i], c + DIR[i+1], maxMove - 1)) % 1000000007;
        return memo[r][c][maxMove] = ans;
    }
};