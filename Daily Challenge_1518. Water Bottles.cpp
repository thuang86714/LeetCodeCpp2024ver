class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, residualBottle = 0;
        while (numBottles > 0) {
            ans += numBottles;
            int curBottle = numBottles + residualBottle;
            residualBottle = curBottle % numExchange;
            numBottles = curBottle / numExchange;
        }
        return ans;
    }
};