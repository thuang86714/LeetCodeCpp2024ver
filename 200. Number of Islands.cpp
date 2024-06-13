#include <vector>

class Solution {
private:
    std::vector<std::vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void findIslandDFS(int x, int y, std::vector<std::vector<char>>& grid){
        grid[x][y] = '0';
        for(const auto &dir:dirs){
            int newX = x + dir[0];
            int newY = y + dir[1];
            if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == '1'){
                findIslandDFS(newX, newY, grid);
            }
        }
    }
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int islandCount = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    islandCount++;
                    findIslandDFS(i, j, grid);
                }
            }
        }
        return islandCount;
    }
};