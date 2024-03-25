#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string removeStars(std::string s) {
        //TC O(n), SC O(n)
        std::stack<char> charStack;
        for(char &ch:s){
            if(ch == '*'){
                charStack.pop();
            }else{
                charStack.push(ch);
            }
        }
        std::string ans = "";
        while(!charStack.empty()){
            ans += charStack.top();
            charStack.pop();
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};