#include <queue>
#include <string>
class Solution {
public:
    std::string predictPartyVictory(std::string senate) {
        //credit to caihao0727mail, TC O(n), SC O(n)
        std::queue<int> rIdxQueue, dIdxQueue;
        int n = senate.size();
        for(int i = 0; i < n; i++){
            if(senate[i] =='R'){
                rIdxQueue.push(i);
            }else{
                dIdxQueue.push(i);
            }
        }

        while(!rIdxQueue.empty() && !dIdxQueue.empty()){
            int rIdx = rIdxQueue.front(), dIdx = dIdxQueue.front();
            rIdxQueue.pop();
            dIdxQueue.pop();
            if(rIdx < dIdx){
                rIdxQueue.push(rIdx + n);//the operation plus n means the corresponding senate can keep "alive" to the next round.
            }else{
                dIdxQueue.push(dIdx + n);
            }
        }

        if(rIdxQueue.size() > dIdxQueue.size()){
            return "Radiant";
        }
        return "Dire";
    }
};