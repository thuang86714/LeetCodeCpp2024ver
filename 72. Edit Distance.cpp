#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        // credit to jianchao li, TC O(n*m), SC O(n*m)
        int m = word1.size(), n = word2.size();
        std::vector<std::vector<int>> memo(m + 1, std::vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            memo[i][0] = i;
        }

        for (int j = 1; j <= n; j++) {
            memo[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    memo[i][j] = memo[i - 1][j - 1];
                } else {
                    memo[i][j] =
                        std::min({memo[i - 1][j],
                                memo[i - 1][j - 1], memo[i][j - 1]}) + 1;
                }
            }
        }
        return memo[m][n];
    }
};