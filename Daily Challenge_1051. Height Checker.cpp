#include <algorithm>
#include <vector>

class Solution {
public:
    int heightChecker(std::vector<int>& heights) {
        //TC O(nlogn), SC O(n)
        std::vector<int> expected{heights.begin(), heights.end()};
        int count = 0;
        std::sort(expected.begin(), expected.end());
        for(int i = 0; i < heights.size(); i++){
            if(expected[i] != heights[i]){
                count++;
            }
        }
        return count;
    }
};