#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid) {
        //TC O(n^2), SC O(1)
        int n = grid.size();
        std::vector<std::vector<int>> result(n - 2, std::vector<int> (n - 2));
        for(int i = 0; i < n - 2; i++){
            for(int j = 0; j < n - 2; j++){
                for(int I = i; I < i + 3; I++){
                    for(int J = j; J < j + 3; J++){
                        result[i][j] = std::max(result[i][j], grid[I][J]);
                    }
                }
            }
        }
        return result;
    }
};