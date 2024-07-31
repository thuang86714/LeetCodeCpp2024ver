#include <string>

class Solution {
public:
    int minimumDeletions(std::string s) {
        // TC O(n), SC O(1), credit to neetcode and arishta
        int aCountRight = 0, bCountLeft = 0, result = s.size();
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == 'a') {
                aCountRight++;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                aCountRight--;
            }
            result = std::min(result, aCountRight + bCountLeft);
            if (s[i] == 'b') {
                bCountLeft++;
            }
        }

        return result;
    }
};