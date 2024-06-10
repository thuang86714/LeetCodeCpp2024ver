#include <vector>
#include <algorithm>
class Solution {
public:
    void reverseString(std::vector<char>& s) {
        //TC O(n), SC O(1)
        int left = 0, right = s.size() - 1;
        while(left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        std::reverse(s.begin(), s.end());
    }
};