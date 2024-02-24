#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //credit to votrubac, TC O(m*n), SC O(1)
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] += min({matrix[i - 1][j], matrix[i - 1][max(0, j - 1)], matrix[i - 1][min(m - 1, j + 1)]});
            }
        }
        return *min_element(matrix[m - 1].begin(), matrix[m - 1].end());
    }
};