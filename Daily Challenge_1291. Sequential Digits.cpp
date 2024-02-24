#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        //credit to NeetCode, TC O(1), SC O(1)
        queue<int> toCalculate;
        for(int i = 1; i <= 9; i++){
            toCalculate.push(i);
        }
        vector<int> ans;
        while(!toCalculate.empty()){
            int cur = toCalculate.front();
            toCalculate.pop();
            if(cur > high){
                continue;
            }
            if(low <= cur && cur <= high){
                ans.push_back(cur);
            }
            int ones = cur%10;
            if(ones < 9){
                int nextNum = cur*10 + ones + 1;
                toCalculate.push(nextNum);
            }
        }
        return ans;
    }
};