#include <string>
#include <vector>

class Solution {
public:
    int minOperations(std::vector<std::string>& logs) {
        int ans = 0;
        for (const std::string& log : logs) {
            if (log == "../") {
                if (ans > 0) {
                    ans--;
                }
            } else if (log == "./") {
                continue;
            } else {
                ans++;
            }
        }
        if (ans < 0) {
            return 0;
        }
        return ans;
    }
};