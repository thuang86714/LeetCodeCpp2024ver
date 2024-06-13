#include <vector>

class Solution {
private:
    std::vector<std::vector<int>> ans;
    void findCombo(std::vector<int>& candidates, int target, int curSum, std::vector<int>& curCombo, int idx){
        if(curSum > target){
            return;
        }
        if(curSum == target){
            ans.push_back(curCombo);
        }

        for(int i = idx; i < candidates.size(); i++){
            curSum += candidates[i];
            curCombo.push_back(candidates[i]);
            findCombo(candidates, target, curSum, curCombo, i);
            curSum -= candidates[i];
            curCombo.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        int curSum = 0;
        std::vector<int> curCombo;
        findCombo(candidates, target, curSum, curCombo, 0);
        return ans;
    }
};