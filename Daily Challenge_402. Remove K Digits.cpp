#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        // credit to knockCat
        //  number of operation greater than length we return an empty string
        if (num.length() <= k)
            return "0";

        // k is 0 , no need of removing /  preforming any operation
        if (k == 0)
            return num;

        std::string res = ""; // result string
        std::stack<char> numStack;   // char stack

        numStack.push(num[0]); // pushing first character into stack

        for (int i = 1; i < num.length(); ++i) {
            while (k > 0 && !numStack.empty() && num[i] < numStack.top()) {
                // if k greater than 0 and our stack is not empty and the
                // upcoming digit, is less than the current top than we will pop
                // the stack top
                --k;
                numStack.pop();
            }

            numStack.push(num[i]);

            // popping preceding zeroes
            if (numStack.size() == 1 && num[i] == '0')
                numStack.pop();
        }

        while (k && !numStack.empty()) {
            // for cases like "456" where every num[i] > num.top()
            --k;
            numStack.pop();
        }

        while (!numStack.empty()) {
            res.push_back(numStack.top()); // pushing stack top to string
            numStack.pop();                // pop the top element
        }

        std::reverse(res.begin(), res.end()); // reverse the string

        if (res.length() == 0)
            return "0";

        return res;
    }
};