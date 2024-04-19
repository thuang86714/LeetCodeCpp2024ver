#include <vector>

class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        //TC O(m*n), SC O(1)
        int cellCount = 0, repeat = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    cellCount++;
                    if(i != 0 && grid[i - 1][j]){
                        repeat++;
                    }
                    if(j != 0 && grid[i][j - 1]){
                        repeat++;
                    }
                }
            }
        }
        return 4*cellCount - 2* repeat;
    }
};
