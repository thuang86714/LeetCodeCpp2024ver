#include <string>
#include <algorithm>

class Solution {
public:
    int scoreOfString(std::string s) {
        //TC O(n), SC O(1)
        int score = 0;
        for(int i = 1; i < s.size(); i++){
            score += std::abs(s[i] - s[i - 1]);
        }
        return score;
    }
};