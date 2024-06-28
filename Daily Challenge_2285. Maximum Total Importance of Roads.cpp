#include <vector>

class Solution {
public:
    long long maximumImportance(int n, std::vector<std::vector<int>>& roads) {
        //TC O(n), SC O(n), counting sort
        std::vector<int> degreeCountVec(n);
        std::vector<int> freqCountVec(n + 1);

        for (const auto& road : roads) {
            degreeCountVec[road[0]]++;
            degreeCountVec[road[1]]++;
        }

        for (const auto& degree : degreeCountVec) {
            freqCountVec[degree]++;
        }

        long long ans = 0;
        int importance = n;

        for (int i = n; i >= 0; i--) {
            while (freqCountVec[i]) {
                ans += static_cast<long long>(i) * importance;
                freqCountVec[i]--;
                importance--;
            }
        }
        return ans;
    }
};