#include <vector>

class Solution {
public:
    int findCenter(std::vector<std::vector<int>>& edges) {
        // find the node with highest degree, TC O(n), SC O(n)
        int ans = 0, curCount = 0;
        const int n = edges.size() + 1;
        std::vector<int> degreeCountVec(n + 1, 0);

        for (const auto& edge : edges) {
            degreeCountVec[edge[0]]++;
            degreeCountVec[edge[1]]++;
        }

        for (int i = 1; i < degreeCountVec.size(); i++) {
            if (curCount < degreeCountVec[i]) {
                curCount = degreeCountVec[i];
                ans = i;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int findCenter(std::vector<std::vector<int>>& edges) {
        // credit to votrubac, TC O(1), SC O(1)
        // Basically, a center node must appear in every edge.
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        } else {
            return edges[0][1];
        }
    }
};