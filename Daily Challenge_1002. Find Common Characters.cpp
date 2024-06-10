#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        //TC O(n*m) where m is average len of all words, SC O(1)
        std::vector<int> charCountVec(26, 0);
        std::vector<std::string> ans;
        for(const char &c:words[0]){
            charCountVec[c - 'a']++;
        }
        for(const std::string &word:words){
            std::vector<int> tempCharCountVec(26, 0);
            for(const char &c:word){
                tempCharCountVec[c - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                charCountVec[i] = std::min(charCountVec[i], tempCharCountVec[i]);
            }
        }

        for(int i = 0; i < 26; i++){
            for(int j = 0; j < charCountVec[i]; j++){
                ans.push_back(std::string(1, i + 'a'));
            }
        }
        return ans;

    }
};