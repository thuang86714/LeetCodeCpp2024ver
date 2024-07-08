#include <string>
#include <vector>
#include <algorithm>
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::sort(strs.begin(), strs.end());
        int count = 0;
        std::string front = strs.front(), back = strs.back();
        int min_len = std::min(front.size(), back.size());
        for(int i = 0; i < min_len; i++){
            if(front[i] != back[i]){
                break;
            }
            count++;
        }

        return front.substr(0, count);
    }
};