#include <queue>
#include <climits>
class Solution {
public:
    long long totalCost(std::vector<int>& costs, int k, int candidates) {
        //credit to rahulvarma5297
        int left = 0, right = costs.size() - 1;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap1;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap2;

        long long ans = 0;
        while (k--) {
            while (minHeap1.size() < candidates && left <= right) {
                minHeap1.push(costs[left++]);
            }
            while (minHeap2.size() < candidates && left <= right) {
                minHeap2.push(costs[right--]);
            }

            int t1 = minHeap1.size() > 0 ? minHeap1.top() : INT_MAX;
            int t2 = minHeap2.size() > 0 ? minHeap2.top() : INT_MAX;

            if (t1 <= t2) {
                ans += t1;
                minHeap1.pop();
            } else {
                ans += t2;
                minHeap2.pop();
            }
        }
        return ans;
    }
};