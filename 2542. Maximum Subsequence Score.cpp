#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        //credit to lee215
        int n = nums1.size();
        std::vector<std::pair<int, int>> ess(n);
        for (int i = 0; i < n; ++i)
            ess[i] = {nums2[i], nums1[i]};
        std::sort(rbegin(ess), rend(ess));
        long long sumS = 0, res = 0;
        std::priority_queue <int, std::vector<int>, std::greater<int>> pq; //min heap
        for (auto& [e, s] : ess) {
            pq.emplace(s);
            sumS += s;
            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
                res = std::max(res, sumS * e);
        }
        return res;
    }
};