#include <vector>
#include <queue>

class Solution {
    //BFS, credit to dd139, TC O(n), SC O(n)
private:
    std::vector<std::vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        std::queue<std::pair<int, int>> toVisit;
        int m = grid.size(), n = grid[0].size(), freshOrange = 0, ans = -1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    freshOrange++;
                }else if(grid[i][j] == 2){
                    toVisit.push({i, j});
                }
            }
        }
        while(!toVisit.empty()){
            int curSize = toVisit.size();
            for(int i = 0; i < curSize; i++){
                auto [row, col] = toVisit.front();
                toVisit.pop();
                for(int j = 0; j < dirs.size(); j++){
                    int newRow = row + dirs[j][0];
                    int newCol = col + dirs[j][1];
                    if(newRow >= 0 && newCol >= 0 && newRow < m && newCol < n && grid[newRow][newCol] == 1){
                        grid[newRow][newCol] = 2;
                        toVisit.push({newRow, newCol});
                        freshOrange--;
                    }
                }
            }
            ans++;
        }
        if(freshOrange > 0){
            return -1;
        }
        if(ans == -1){
            return 0;
        }
        return ans;
    }
};