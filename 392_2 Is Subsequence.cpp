#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int idxS = 0, idxT = 0;
        while (idxS < s.size() && idxT < t.size()) {
            if (s[idxS] == t[idxT]) {
                idxS++;
            }
            idxT++;
        }
        return idxS == s.size();
    }
};