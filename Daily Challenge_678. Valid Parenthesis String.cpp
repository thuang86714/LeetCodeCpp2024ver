#include <string>

class Solution {
public:
    bool checkValidString(std::string s) {
        // credit to hiepit, TC O(n), SC O(1)
        int minOpenPairCount = 0, maxOpenPairCount = 0;
        for (const char& ch : s) {
            if (ch == '(') {
                minOpenPairCount++;
                maxOpenPairCount++;
            } else if (ch == ')') {
                minOpenPairCount--;
                maxOpenPairCount--;
            }else if(ch == '*'){
                maxOpenPairCount++;// if `*` become `(` then openCount++
                minOpenPairCount--; // if `*` become `)` then openCount--
                // if `*` become `` then nothing happens
                // So openCount will be in new range [cmin-1, cmax+1]
            }
            if(maxOpenPairCount < 0){
                return false;
            }

            minOpenPairCount = std::max(0, minOpenPairCount);
        }
        return minOpenPairCount == 0;
    }
};