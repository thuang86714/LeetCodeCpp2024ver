#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        //TC O(nlogn), SC O(n)
        std::unordered_map<int, int> rankMap;
        int rank = 1;
        std::priority_queue<int> scoreMaxHeap{score.begin(), score.end()};
        while(!scoreMaxHeap.empty()){
            int curScore = scoreMaxHeap.top();
            scoreMaxHeap.pop();
            rankMap[curScore] = rank;
            rank++;
        }

        std::vector<std::string> ans(score.size());
        for(int i = 0; i < score.size(); i++){
            switch (rankMap[score[i]]) {
                case 1:
                    ans[i] = "Gold Medal";
                    break;
                case 2:
                    ans[i] = "Silver Medal";
                    break;
                case 3:
                    ans[i] = "Bronze Medal";
                    break;
                default:
                    ans[i] = std::to_string(rankMap[score[i]]);
                    break;
            }
        }

        return ans;
    }
};