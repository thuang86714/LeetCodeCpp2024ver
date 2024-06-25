#include <vector>

class Solution {
public:
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
        int totalSatisfied = 0, curIncrease = 0, maxIncrease = 0;
        for(int i = 0; i < customers.size(); i++){
            if(grumpy[i] == 0){
                totalSatisfied += customers[i];
            }
        }

        for(int i = 0; i < minutes; i++){
            if(grumpy[i] == 1){
                curIncrease += customers[i];
            }
        }
        maxIncrease = curIncrease;

        for(int i = minutes; i < customers.size(); i++){
            if(grumpy[i] == 1){
                curIncrease += customers[i];
            }
            if(grumpy[i-minutes] == 1){
                curIncrease -= customers[i-minutes];
            }
            maxIncrease = std::max(maxIncrease, curIncrease);
        }

        return totalSatisfied + maxIncrease;
    }
};