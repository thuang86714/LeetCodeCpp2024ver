#include <queue>
#include <vector>
#include <array>

class Solution {
public:
    int maximumSafenessFactor(std::vector<std::vector<int>>& grid) {
        std::queue<std::array<int, 2>> safenessQueue;
        int dir[5] = {1, 0, -1, 0, 1}, n = grid.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j])
                    safenessQueue.push({i, j});
        while (!safenessQueue.empty()) {
            auto [i, j] = safenessQueue.front();
            safenessQueue.pop();
            for (int d = 0; d < 4; ++d) {
                int x = i + dir[d], y = j + dir[d + 1];
                if (std::min(x, y) >= 0 && std::max(x, y) < n && grid[x][y] == 0) {
                    grid[x][y] = grid[i][j] + 1;
                    safenessQueue.push({x, y});
                }
            }
        }
        std::priority_queue<std::array<int, 3>> dijSafenessMaxHeap;
        dijSafenessMaxHeap.push({grid[0][0], 0, 0});
        while (dijSafenessMaxHeap.top()[1] < n - 1 || dijSafenessMaxHeap.top()[2] < n - 1) {
            auto [sf, i, j] = dijSafenessMaxHeap.top();
            dijSafenessMaxHeap.pop();
            for (int d = 0; d < 4; ++d) {
                int x = i + dir[d], y = j + dir[d + 1];
                if (std::min(x, y) >= 0 && std::max(x, y) < n && grid[x][y] > 0) {
                    dijSafenessMaxHeap.push({std::min(sf, grid[x][y]), x, y});
                    grid[x][y] *= -1;
                }
            }
        }
        return dijSafenessMaxHeap.top()[0] - 1;
    }
};