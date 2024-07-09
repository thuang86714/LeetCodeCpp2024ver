#include <string>
#include <unordered_map>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> charCountMap;
        for (const char& c : magazine) {
            charCountMap[c]++;
        }
        for (const char& c : ransomNote) {
            charCountMap[c]--;
            if (charCountMap[c] < 0) {
                return false;
            }
        }
        return true;
    }
};