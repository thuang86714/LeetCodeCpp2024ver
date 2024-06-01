#include <string>
#include <cmath>

class Solution {
public:
    int equalSubstring(std::string s, std::string t, int maxCost) {
        int maxLen = 0, curDiff = 0, left = 0;
        for(int right = 0; right < s.size(); right++){
            curDiff += std::abs(s[right] - t[right]);
            
            // Shrink the window until the cost is within the allowed limit
            while (curDiff > maxCost) {
                curDiff -= std::abs(s[left] - t[left]);
                left++;
            }
            
            // Update the maximum length of the valid window
            maxLen = std::max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};