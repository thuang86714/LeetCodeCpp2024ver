#include <vector>
#include <string>

class Solution {
public:
    int countSeniors(std::vector<std::string>& details) {
        int count = 0;
        for (const std::string& detail : details) {
            int curNum = 10 * (detail[11] - '0') + (detail[12] - '0');
            if (curNum > 60) {
                count++;
            }
        }

        return count;
    }
};