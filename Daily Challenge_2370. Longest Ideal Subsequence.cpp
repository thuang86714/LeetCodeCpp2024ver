#include <unordered_map>
#include <string>
#include <algorithm>

class Solution {
public:
    int longestIdealString(std::string s, int k) {
        //TC O(n*k), SC O(n)
        std::unordered_map<char, int> charMemoMap;
        int ans = 1;
        charMemoMap[s[0]] = 1;
        for(int i = 1; i < s.size(); i++){
            int curMemo = 0;
            for(int j = -k; j <= k; j++){
                if(charMemoMap.count(s[i] + j)){
                    curMemo = std::max(curMemo, charMemoMap[s[i] + j]);
                }
            }
            charMemoMap[s[i]] = curMemo + 1;
            ans = std::max(ans, charMemoMap[s[i]]);
        }
        return ans;
    }
};