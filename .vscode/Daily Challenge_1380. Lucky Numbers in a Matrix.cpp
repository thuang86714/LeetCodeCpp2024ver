#include <vector>

class Solution {
public:
    std::vector<int> luckyNumbers(std::vector<std::vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        std::vector<int> maxCol = matrix[0], result, minRow(m, 0);

        for (int i = 0; i < m; i++) {
            int curMin = 1000000;
            for (int j = 0; j < n; j++) {
                maxCol[j] = std::max(maxCol[j], matrix[i][j]);
                curMin = std::min(curMin, matrix[i][j]);
            }
            minRow[i] = curMin;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (maxCol[j] == minRow[i]) {
                    result.push_back(maxCol[j]);
                }
            }
        }
        return result;
    }
};