#include <string>
#include <algorithm>

class Solution {
public:
    std::string reversePrefix(std::string word, char ch) {
        //TC O(n), SC O(1) 
        int idx = 0;
        for(; idx < word.size(); idx++){
            if(word[idx] == ch){
                break;
            }
        }
        if(idx == word.size()){
            return word;
        }
        std::reverse(word.begin(), word.begin() + idx + 1);
        return word;
    }
};