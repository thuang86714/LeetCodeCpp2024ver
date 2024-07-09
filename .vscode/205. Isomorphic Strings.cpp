#include <string>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> map1, map2;

        for (int i = 0; i < s.size(); i++) {
            if (!map1.count(s[i]) && !map2.count(t[i])) {
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            } else if (map1.count(s[i]) && map2.count(t[i])) {
                if (map1[s[i]] != t[i] || map2[t[i]] != s[i])
                    return false;
            } else {
                return false;
            }
        }
        return true;
    }
};