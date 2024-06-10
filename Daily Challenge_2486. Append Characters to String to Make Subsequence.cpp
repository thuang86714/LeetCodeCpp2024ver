#include <string>

class Solution {
public:
    int appendCharacters(std::string s, std::string t) {
        //TC O(n), SC O(1)
        int sIdx = 0, tIdx = 0;
        while(sIdx < s.size() && tIdx < t.size()){
            if(s[sIdx] == t[tIdx]){
                tIdx++;
            }
            sIdx++;
        }
        return t.size() - tIdx;
    }
};