#include <string>
#include <stack>
#include <algorithm>
class Solution {
public:
    std::string reverseParentheses(std::string s) {
        std::stack<std::string> stack;

        for (char c : s) {
            if (c == '(') {
                stack.push("(");
            } else if (c == ')') {
                std::string rev;
                while (!stack.empty() && stack.top() != "(") {
                    std::reverse(stack.top().begin(), stack.top().end());
                    rev += stack.top();
                    stack.pop();
                }
                stack.pop(); // Pop the '('
                stack.push(rev);
            } else {
                stack.push(std::string(1, c));
            }
        }

        std::string result;
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }

        return result;
    }
};