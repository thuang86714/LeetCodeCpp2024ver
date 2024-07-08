#include <unordered_map>
#include <string>

class Solution {
private:
    std::unordered_map<char, int> charToIntMap{
        {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}};

public:
    int romanToInt(std::string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i < s.size() - 1 &&
                charToIntMap[s[i]] < charToIntMap[s[i + 1]]) {
                ans -= charToIntMap[s[i]];
            } else {
                ans += charToIntMap[s[i]];
            }
        }
        return ans;
    }
};