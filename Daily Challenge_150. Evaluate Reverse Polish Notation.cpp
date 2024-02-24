#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //TC O(n), SC O(n)
        stack<int> st;
        for(string str: tokens){
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                int op;
                if(str == "+"){
                    op = op1 + op2;
                }else if(str == "-"){
                    op = op1 - op2;
                }else if(str == "*"){
                    op = op1 * op2;
                }else{
                    op = op1/ op2;
                }
                st.push(op);
            }else{
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};