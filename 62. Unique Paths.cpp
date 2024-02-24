#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        //credit to archit91, TC O(min(m,n)), SC O(1)
        long ans = 1;
        for(int i = m+n-2, j = 1; i >= max(m, n); i--, j++) 
            ans = (ans * i) / j;
        return ans;
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        //TC O(m*n), SC O(n)
        vector<int> row(n, 1);
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                row[j] += row[j - 1];
            }
        }
        return row.back();
    }
};