#include <queue>

class RecentCounter {
    //credit to pranjalgururani
private:
    std::queue<int> callHistoryQueue;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        callHistoryQueue.push(t);
        
        while(callHistoryQueue.front() < t - 3000){

            callHistoryQueue.pop();
        }
        return callHistoryQueue.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */