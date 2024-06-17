#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        //TC O(s.length), SC O(s.length)
        int left = 0, right = 0, maxLen = 0;
        std::unordered_map<char, int> charCountMap;
        for(; right < s.length(); right++){
            charCountMap[s[right]]++;

            while(charCountMap[s[right]] > 1){
                charCountMap[s[left]]--;
                left++;
            }

            maxLen = std::max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};