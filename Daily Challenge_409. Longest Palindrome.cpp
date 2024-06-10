#include <string>
#include <unordered_map>
class Solution {
public:
    int longestPalindrome(std::string s) {
        bool hasOddCount = false;
        int length = 0;
        std::unordered_map<char, int> charCountMap;
        for(char c:s){
            charCountMap[c]++;
        }
        for(const auto &charCount:charCountMap){
            if(charCount.second%2 == 0){
                length += charCount.second;
            }else{
                hasOddCount = true;
                length += charCount.second - 1;
            }
        }
        if(hasOddCount){
            length += 1;
        }
        return length;
    }
};