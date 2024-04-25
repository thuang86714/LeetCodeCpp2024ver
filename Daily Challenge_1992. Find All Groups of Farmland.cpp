#include <vector>

class Solution {
private:
    std::vector<std::vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    std::vector<std::vector<int>> ans;
    void findThisFarmland(int x, int y, std::vector<std::vector<int>>& land, std::vector<int> curCoordinates){
        //dfs
        int nextCellCount = 0;
        land[x][y] = 0;
        for(auto &dir:dirs){
            int newX = x + dir[0];
            int newY = y + dir[1];
            if(newX >= 0 && newX < land.size() && newY >= 0 && newY < land[0].size() && land[newX][newY]){
                nextCellCount++;
                if(newX >= curCoordinates[2] && newY>= curCoordinates[3]){
                    curCoordinates[2] = newX;
                    curCoordinates[3] = newY;
                }
                findThisFarmland(newX, newY, land, curCoordinates);
            }
        }
        if(!nextCellCount){
            ans.push_back(curCoordinates);
        }
    }
public:
    std::vector<std::vector<int>> findFarmland(std::vector<std::vector<int>>& land) {
        for(int i = 0; i < land.size(); i++){
            for(int j = 0; j < land[0].size(); j++){
                if(land[i][j]){
                    std::vector<int> temp{i, j, i, j};
                    findThisFarmland(i, j, land, temp);
                }
            }
        }
        return ans;
    }
};