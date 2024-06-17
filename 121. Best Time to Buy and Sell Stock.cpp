#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int curMin = 10001, curProfit = 0;
        for(const int &price:prices){
            curMin = std::min(curMin, price);
            curProfit = std::max(curProfit, price - curMin);
        }
        return curProfit;
    }
};