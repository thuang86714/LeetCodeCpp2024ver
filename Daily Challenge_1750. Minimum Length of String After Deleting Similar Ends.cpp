#include <string>

class Solution {
public:
    int minimumLength(std::string s) {
        //credit to DevOgabek, two pointer, TC O(n), SC O(1)
        int left = 0, right = s.size() - 1;
        while(left < right && s[left] == s[right]){
            char cur = s[left];
            while(left <= right && s[left] == cur){
                left++;
            }
            while(left <= right && s[right] == cur){
                right--;
            }
        }
        return right - left + 1;
    }
};