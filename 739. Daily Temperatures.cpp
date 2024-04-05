#include <stack>
#include <vector>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        //credit to riemeltm, TC O(n), SC O(n)
        int n = temperatures.size();
        std::stack<int> indexStack;
        std::vector<int> result(n, 0);//for every element in this vector is the distance between current element (temperature) and the next greater element

        //iterate from the back of the array
        for(int i = n - 1; i >= 0; i--){
            /*
            O(1) -->because each element is pushed and popped from the stack at most once across the entire execution
            */
            while(!indexStack.empty() && temperatures[indexStack.top()] <= temperatures[i]){
                indexStack.pop();
            }

            if(!indexStack.empty()){
                result[i] = indexStack.top() - i;//the distance, otherwise 0
            }

            indexStack.push(i);
        }
        return result;
    }
};