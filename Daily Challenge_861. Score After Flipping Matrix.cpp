#include <vector>

class Solution {
public:
    int matrixScore(std::vector<std::vector<int>>& grid) {
        //TC O(m*n), SC O(1)
        //the key is to get as more 1 as we can
        int m = grid.size(), n = grid[0].size();
        //iterate by row to see if this row needs to be fliped
        for(int i = 0; i < m; i++){
            int rowSum = 0;
            for(int j = 0; j < n; j++){
                //every element in a row is weighted
                rowSum *= 2;
                if(grid[i][j]){
                    rowSum += 1;
                }else{
                    rowSum -= 1;
                }
            }
            //early return
            if(rowSum >= 0){
                continue;
            }
            for(int j = 0; j < n; j++){
                grid[i][j] = !grid[i][j];
            }
        }

        //iterate by column to see if this row needs to be fliped
        for(int j = 0; j < n; j++){
            int colSum = 0;
            for(int i = 0; i < m; i++){
                if(grid[i][j]){
                    colSum += 1;
                }else{
                    colSum -= 1;
                }
            }
            //early return
            if(colSum >= 0){
                continue;
            }
            for(int i = 0; i < m; i++){
                grid[i][j] = !grid[i][j];
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++){
            int rowSum = 0;
            for(int j = 0; j < n; j++){
                rowSum *= 2;
                rowSum += grid[i][j];
            }
            ans += rowSum;
        }
        return ans;
    }
};