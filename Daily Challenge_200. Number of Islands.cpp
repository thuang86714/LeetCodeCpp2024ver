#include <vector>

//dfs
class Solution {
private:
    std::vector<std::vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void findThisIsland(int x, int y, std::vector<std::vector<char>>& grid){
        if(grid[x][y] != '1'){
            return;
        }
        grid[x][y] = '0';
        for(int i = 0; i < dirs.size(); i++){
            int newX = x + dirs[i][0];
            int newY = y + dirs[i][1];
            if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size()){
                findThisIsland(newX, newY, grid);
            }
        }
    }
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        //dfs, TC O(m*n), SC O(m*n)
        int islandCount = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    islandCount++;
                    findThisIsland(i, j, grid);
                }
            }
        }
        return islandCount;
    }
};

#include <queue>
//bfs, TC O(m*n), SC O(m*n)
class Solution {
private:
    std::vector<std::vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void findThisIsland(int x, int y, std::vector<std::vector<char>>& grid){
        std::queue<std::pair<int, int>> toVisitQueue;
        toVisitQueue.push({x, y});
        grid[x][y] = '0';
        while(!toVisitQueue.empty()){
            auto [curX, curY] = toVisitQueue.front();
            toVisitQueue.pop();

            for(auto &dir: dirs){
                int newX = curX + dir[0];
                int newY = curY + dir[1];
                // Ensure the new coordinates are within the grid boundaries and the cell is not visited
                if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == '1') {
                    toVisitQueue.push({newX, newY});
                    grid[newX][newY] = '0';  // Mark as visited
                }
            }
        }
        return;
    }
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int islandCount = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    islandCount++;
                    findThisIsland(i, j, grid);
                }
            }
        }
        return islandCount;
    }
};