#include <vector>
#include <string>

class Solution {
private:
    std::vector<std::vector<std::string>> res;
    bool isPalindrome(std::string& s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--]){
                return false;
            }
        }
        return true;
    }
    void findPalindrome(std::string s, int idx, std::vector<std::string> temp){
        if(idx == s.size()){
            res.push_back(temp);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            if(isPalindrome(s, idx, i)){
                temp.push_back(s.substr(idx, i - idx + 1));
                findPalindrome(s, i + 1, temp);
                temp.pop_back();
            }
        }
    }
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::string> temp;
        findPalindrome(s, 0, temp);
        return res;
    }
};