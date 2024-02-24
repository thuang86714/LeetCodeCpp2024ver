#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //stack LIFO
        //credit to riemeltm
        //TC O(n), SC O(n)
        stack<int> intStac;//store the index of elements
        
        int n = temperatures.size();
        vector<int> result(n, 0);
        for(int i = n - 1; i >= 0;i--){
            while(!intStac.empty() && temperatures[intStac.top()] <= temperatures[i]){
                intStac.pop();
            }

            if(!intStac.empty()){
                result[i] = intStac.top() - i;
            }

            intStac.push(i);
        }
        return result;
    }
};