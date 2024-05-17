#include <vector>

#include <vector>

class Solution {
private:
    std::vector<std::vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool isValid(int newX, int newY, std::vector<std::vector<int>>& grid){
        if(newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[0].size()){
            return false;
        }
        return grid[newX][newY] > 0;
    }
    int collectGold(int x, int y, std::vector<std::vector<int>>& grid){
        int curGold = grid[x][y];
        grid[x][y] = 0;  // Mark the cell as visited by setting it to 0
        int maxNextStep = 0;
        for(int i = 0; i < dirs.size(); i++){
            int newX = x + dirs[i][0];
            int newY = y + dirs[i][1];
            if(isValid(newX, newY, grid)){
                maxNextStep = std::max(maxNextStep, collectGold(newX, newY, grid));
            }
        }
        grid[x][y] = curGold;

        return grid[x][y] + maxNextStep;
    }
public:
    int getMaximumGold(std::vector<std::vector<int>>& grid) {
        /*
        Time: O(k * 3 ^ k), where k is the number of cells with gold. We perform the analysis for k cells, and from each cell we can go in three directions.
        Memory: O(k) for the recursion.
        */
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    ans = std::max(ans, collectGold(i, j, grid));
                }
            }
        }
        return ans;
    }
};