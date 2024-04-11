#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
        //TC O(nlogn), SC O(n)
        std::sort(deck.begin(), deck.end());
        std::vector<int> ans;
        std::queue<int> deckQueue;
        //reverse the reveal and pop operation
        for(int i = deck.size() - 1; i >= 0; i--){
            deckQueue.push(deck[i]);
            if(i > 0){     
                int cur = deckQueue.front();
                deckQueue.pop();
                deckQueue.push(cur);
            }
        }

        while(!deckQueue.empty()){
            int cur = deckQueue.front();
            deckQueue.pop();
            ans.push_back(cur);
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};