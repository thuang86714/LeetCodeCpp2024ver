#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        //credit to votrubac, TC O(n^2), SC O(1)
        /*
        credit to taserface:
        If firstMinCur of two rows share the same column, 
        then take 
        min(firstMinCur + secondMinNext, secondMinCur + firstMinNext)
        */
        int firstMinCur = 0, secondMinCur = 0, posCur = -1, n = grid.size();
        for(int i = 0; i < n; i++){
            int firstMinNext = INT_MAX, secondMinNext = INT_MAX, posNext = -1;
            for(int j = 0; j < n; j++){
                int curMemo;
                if(j == posCur){
                    curMemo = secondMinCur;
                }else{
                    curMemo = firstMinCur;
                }
                if(grid[i][j] + curMemo < firstMinNext){
                    secondMinNext = firstMinNext;
                    firstMinNext = grid[i][j] + curMemo;
                    posNext = j;
                }else{
                    secondMinNext = std::min(secondMinNext, grid[i][j] + curMemo);
                }
            }
            firstMinCur = firstMinNext, secondMinCur = secondMinNext, posCur = posNext;
        }
        return firstMinCur;
    }
};