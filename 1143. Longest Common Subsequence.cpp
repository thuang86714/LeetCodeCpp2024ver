#include <string>
#include <algorithm>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        //credit to votrbac, TC O(n*m), SC O(1)
        int dp[1001][1001] = {};
        for (int i = 0; i < text1.size(); i++) {
            for (int j = 0; j < text2.size(); j++) {
                dp[i + 1][j + 1] = text1[i] == text2[j]
                                       ? dp[i][j] + 1
                                       : std::max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};