#include <vector>

class Solution {
public:
    // Calculates the number of equal pairs of rows and columns in a grid.
    // An equal pair is defined as a row and a corresponding column that have the same elements in the same order.
    // Time Complexity: O(n^2), where n is the dimension of the grid.
    // Space Complexity: O(n^2), due to storing the transposed grid for comparison.
    int equalPairs(std::vector<std::vector<int>>& grid) {
        int equalPairsCount = 0, gridSize = grid.size();
        std::vector<std::vector<int>> transposedGrid(gridSize, std::vector<int>(gridSize , 0));
        for(int row = 0; row < gridSize; row++){
            for(int col = 0; col < gridSize; col++){
                transposedGrid[row][col] = grid[col][row];
            }
        }
        for(int row = 0; row < gridSize; row++){
            for(int col = 0; col < gridSize; col++){
                if(grid[row] == transposedGrid[col]){
                    equalPairsCount++;
                }
            }
        }
        return equalPairsCount;
    }
};


#include <vector>
#include <unordered_map>
#include <string>

class Solution {
 public:
  // Calculates the number of equal pairs of rows and columns in the grid.
  // Equal pairs are defined where a row and a column contain the same elements in the same order.
  // Uses string serialization of rows and columns for comparison.
  //TC O(n^2), SC O(n^2)
  int EqualPairs(const std::vector<std::vector<int>>& grid) {
    const int n = grid.size();
    std::unordered_map<std::string, int> rowPatterns;
    int equalPairsCount = 0;

    // Convert each row to a string pattern and count occurrences.
    for (int i = 0; i < n; ++i) {
      std::string rowPattern;
      for (int j = 0; j < n; ++j) {
        rowPattern += std::to_string(grid[i][j]) + ",";
      }
      ++rowPatterns[rowPattern];
    }

    // Compare each column to the row patterns by converting columns to strings.
    for (int j = 0; j < n; ++j) {
      std::string colPattern;
      for (int i = 0; i < n; ++i) {
        colPattern += std::to_string(grid[i][j]) + ",";
      }
      equalPairsCount += rowPatterns[colPattern];
    }

    return equalPairsCount;
  }
};

