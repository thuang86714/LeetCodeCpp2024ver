#include <unordered_set>
#include <string>

class Solution {
private:
    std::unordered_set<char> dict{'a', 'e', 'i', 'o', 'u'};
public:
    int maxVowels(std::string s, int k) {
        //TC O(n), SC O(1)
        int left = 0, right = 0, maxCount = 0, curCount = 0;
        while(left < s.size() && right < s.size()){//sliding window with fixed size = k
            while(right < s.size() && right - left + 1 <= k){
                if(dict.count(s[right])){
                    curCount++;
                }
                right++;
            }
            maxCount = std::max(maxCount, curCount);
            if(dict.count(s[left++])){
                curCount--;
            }
        }
        return maxCount;
    }
};