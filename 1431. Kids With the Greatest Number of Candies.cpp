#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        //TC O(n), SC O(1)
        int curMax = *max_element(candies.begin(), candies.end());
        vector<bool> ans(candies.size(), false);
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= curMax){
                ans[i] = true;
            }
        }
        return ans;
    }
};