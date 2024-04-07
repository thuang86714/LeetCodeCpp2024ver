#include <string>
#include <stack>

class Solution {
public:
    std::string minRemoveToMakeValid(std::string s) {
        //TC O(n), SC O(n)
        std::string result = "";
        std::stack<char> parenthesesStack;
        int pairCount = 0;
        //first pass we count the number of valid parentheses
        for(const char &ch:s){
            if(isalpha(ch)){
                continue;
            }
            if(ch == '('){
                parenthesesStack.push(ch);
            }else{
                if(!parenthesesStack.empty() && parenthesesStack.top() == '('){
                    parenthesesStack.pop();
                    pairCount++;
                }
            }
        }
        //second pass we build the string according to what we get in the first pass
        int leftCount = pairCount, rightCount = pairCount;
        for(const char &ch:s){
            if(isalpha(ch)){
                result += ch;
            }
            if(ch == '(' && leftCount){
                result += ch;
                leftCount--;
            }
            if(ch == ')' && rightCount && rightCount > leftCount){
                result += ch;
                rightCount--;
            }
        }
        return result;
    }
};