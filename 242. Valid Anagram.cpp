#include <unordered_map>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> charCountMap;
        for (const char& c : s) {
            charCountMap[c]++;
        }
        for (const char& c : t) {
            charCountMap[c]--;
        }

        for (const auto& item : charCountMap) {
            if (item.second != 0) {
                return false;
            }
        }
        return true;
    }
};