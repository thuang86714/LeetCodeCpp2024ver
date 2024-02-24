#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        //TC O(n), SC O(1)
        vector<int> charCounter (26, 0);
        for(char c:s){
            charCounter[c - 'a']++;
        }
        for(int i = 0; i < s.size(); i++){
            if(charCounter[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};