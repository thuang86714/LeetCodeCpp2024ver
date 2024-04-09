#include <queue>
#include <vector>

class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        //TC O(sum(tickets)), SC O(n)
        std::queue<std::pair<int, int>> ticketQueue;
        for(int i = 0; i < tickets.size(); i++){
            ticketQueue.push({tickets[i], i});
        }

        int count = 0;
        while(!ticketQueue.empty()){
            auto [ticketCount, idx] = ticketQueue.front();
            ticketQueue.pop();
            count++;
            if(--ticketCount == 0 && idx == k){
                return count;
            }
            if(ticketCount > 0){
                ticketQueue.push({ticketCount, idx});
            }
        }
        return 0;
    }
};

class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        //credit to lzl124631x, TC O(n), SC O(1)
        int step = 0;
        for(int i = 0; i < tickets.size(); i++){
            if(i <= k){
                step += std::min(tickets[k], tickets[i]);
            }else{
                step += std::min(tickets[k] - 1, tickets[i]);
            }
        }
        return step;
    }
};