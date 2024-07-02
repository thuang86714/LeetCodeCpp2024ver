#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        //TC O(n), SC O(1)
        std::unordered_map<char, int> charCountMap;
        int left = 0, ans = 0;
        for(int right = 0; right < s.size(); right++){
            charCountMap[s[right]]++;

            while(left < right && charCountMap[s[right]] > 1){
                charCountMap[s[left]]--;
                left++;
            }
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
};