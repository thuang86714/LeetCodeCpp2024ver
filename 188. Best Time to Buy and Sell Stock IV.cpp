#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>> (k + 1, vector<int> (2, 0)));
        for(int i = 0; i < n; i++){
            for(int j = k; j >= 1; j--){
                if(i == 0){
                    memo[i][j][0] = 0;
                    memo[i][j][1] = -1*prices[i];
                    continue;
                }
                memo[i][j][0] = max(memo[i - 1][j][0], memo[i - 1][j][1] + prices[i]);
                memo[i][j][1] = max(memo[i - 1][j][1], memo[i - 1][j - 1][0] - prices[i]);
            }
        }
        return memo[n - 1][k][0];
    }
};