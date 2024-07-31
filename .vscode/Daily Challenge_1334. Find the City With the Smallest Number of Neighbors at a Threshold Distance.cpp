#include <vector>
class Solution {
public:
    int findTheCity(int n, std::vector<std::vector<int>>& edges,
                    int distanceThreshold) {
        std::vector<std::vector<int>> graph(n, std::vector<int>(n, 10001));
        int res = 0, smallest = n;
        for (const auto& e : edges) {
            graph[e[0]][e[1]] = graph[e[1]][e[0]] = e[2];
        }
        for (int i = 0; i < n; ++i) {
            graph[i][i] = 0;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (graph[i][j] <= distanceThreshold) {
                    ++count;
                }
            }
            if (count <= smallest) {
                res = i;
                smallest = count;
            }
        }
        return res;
    }
};