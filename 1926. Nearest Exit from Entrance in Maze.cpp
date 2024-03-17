#include <vector>
#include <queue>

class Solution {
private:
    std::vector<std::vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
public:
    int nearestExit(std::vector<std::vector<char>>& maze, std::vector<int>& entrance) {
        //TC O(n), SC O(n)
        std::queue<std::pair<int, int>> toVisit;
        toVisit.push({entrance[0], entrance[1]});
        int m = maze.size(), n = maze[0].size(), ans = 0;
        maze[entrance[0]][entrance[1]] = '+';
        while(!toVisit.empty()){
            int curSize = toVisit.size();
            for(int i = 0; i < curSize; i++){
                auto [row, col] = toVisit.front();
                toVisit.pop();
                if((row == 0 || col == 0 || row == m - 1 || col == n - 1) && !(row == entrance[0] && col == entrance[1])){// Check if we are on the border but not at the entrance
                    return ans;
                }
                for(int j = 0; j < dirs.size(); j++){
                    int newRow = row + dirs[j][0], newCol = col + dirs[j][1];
                    if(newRow >= 0 && newCol >= 0 && newRow < m && newCol < n && maze[newRow][newCol] == '.'){
                        toVisit.push({newRow, newCol});
                        maze[newRow][newCol] = '+';
                    }
                }      
            }
            ans++;
        }
        return -1;
    }
};