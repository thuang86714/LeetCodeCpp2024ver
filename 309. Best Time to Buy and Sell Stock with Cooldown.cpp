#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //TC O(n), SC O(n)
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, 0));
        for(int i = 0; i < n; i++){
            if(i == 0){
                memo[i][0] = 0;
                memo[i][1] = -1 *prices[i];
                continue;
            }
            if(i == 1){
                memo[i][0] = max(memo[i - 1][0], memo[i - 1][1] + prices[i]);
                memo[i][1] = max(memo[i - 1][1], memo[i - 1][0] - prices[i]);
                continue;
            }

            memo[i][0] = max(memo[i - 1][0], memo[i - 1][1] + prices[i]);
            memo[i][1] = max(memo[i - 1][1], memo[i - 2][0] - prices[i]);
        }

        return memo[n - 1][0];
    }
};