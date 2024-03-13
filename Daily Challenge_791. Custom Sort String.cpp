#include <string>
#include <vector>

class Solution {
public:
    std::string customSortString(std::string order, std::string s) {
        //TC O(n + m), where n and m are the length of order and s respectively, SC O(1)
        std::vector<int> charCount(26, 0);//count the appearance of char

        for(const char &ch:s){//then we know the overall appearance of s
            charCount[ch - 'a']++;
        }

        std::string ans = "";//an empty string as answer

        // Construct the answer based on the order.
        for(const char &ch:order){
            if(charCount[ch - 'a'] > 0){
                ans += std::string(charCount[ch - 'a'], ch);
                charCount[ch - 'a'] = 0;
            }
        }

        // Add remaining characters not in order.
        for(int i = 0; i < 26; i++){
            if(charCount[i] > 0){
                ans += std::string(charCount[i], 'a' + i);
            }
        }

        return ans;
    }
};