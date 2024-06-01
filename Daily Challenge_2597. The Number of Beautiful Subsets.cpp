#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int beautifulSubsets(std::vector<int>& A, int k) {
        /*
        Time Complexity: O(n+k⋅m⋅log(m))
    	Space Complexity: O(n)
        */
        // Initialize count vector with k empty unordered_maps
        std::vector<std::unordered_map<int, int>> count(k);
        
        // Count occurrences of each element in A, grouped by modulo k
        for (int a : A) {
            count[a % k][a]++;
        }

        int res = 1;
        
        // Process each group of elements with the same modulo k value
        for (int i = 0; i < k; i++) {
            int prev = 0, dp0 = 1, dp1 = 0;
            std::vector<int> keys;
            
            // Extract the keys (unique elements) in the current group
            for (auto& p : count[i]) {
                keys.push_back(p.first);
            }
            
            // Sort the keys
            std::sort(keys.begin(), keys.end());

            // Iterate through the sorted keys
            for (int a : keys) {
                int v = std::pow(2, count[i][a]);  // Calculate power of 2 for the count of the current element
                
                if (prev + k == a) {
                    int new_dp0 = dp0 + dp1;
                    dp1 = dp0 * (v - 1);
                    dp0 = new_dp0;
                } else {
                    int new_dp0 = dp0 + dp1;
                    dp1 = (dp0 + dp1) * (v - 1);
                    dp0 = new_dp0;
                }
                prev = a;
            }
            res *= dp0 + dp1;
        }
        return res - 1;
    }
};
