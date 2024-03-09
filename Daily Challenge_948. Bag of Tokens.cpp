#include <algorithm>
#include <vector>
#include <numeric>

class Solution {
public:
    int bagOfTokensScore(std::vector<int>& tokens, int power) {
        //TC O(nlogn), SC O(1), greedy
        int score = 0;
        std::sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size() - 1, ans = 0;
        while(left <= right){
            if(tokens[left] <= power){
                ans = std::max(ans, ++score);
                power -= tokens[left++];
            }else if(score > 0){
                score--;
                power += tokens[right--];
            }else{
                break;
            }
        }
        return ans;
    }
};