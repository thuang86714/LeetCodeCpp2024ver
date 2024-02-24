#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() <= 2){
            return *min_element(cost.begin(), cost.end());
        }

        int oneStep = cost[1], twoStep = cost[0], cur = 0;
        for(int i = 2; i < cost.size(); i++){
            cur = cost[i] + min(oneStep, twoStep);
            twoStep = oneStep;
            oneStep = cur;
        }
        return min(cur, twoStep);
    }
};