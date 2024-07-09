#include <vector>
#include <algorithm>

class Solution {
public:
    double averageWaitingTime(std::vector<std::vector<int>>& customers) {
        int customerCount = customers.size(), startingTime = 0,lastFinishTime = customers[0][0];
        long long timeSum = 0;
        for (const auto& order : customers) {
            startingTime = std::max(lastFinishTime, order[0]);
            timeSum += startingTime + order[1] - order[0];
            lastFinishTime = startingTime + order[1];
        }
        return double(timeSum) / double(customerCount);
    }
};