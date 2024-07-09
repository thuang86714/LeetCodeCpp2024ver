#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle == "") {
            return 0;
        }
        int haystackLen = haystack.size(), needleLen = needle.size();
        for (int i = 0; i < haystackLen - needleLen + 1; i++) {
            if (haystack.substr(i, needleLen) == needle) {
                return i;
            }
        }
        return -1;
    }
};