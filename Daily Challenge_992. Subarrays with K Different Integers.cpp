#include <vector>
#include <unordered_map>

class Solution {
private:
    int atMostK(std::vector<int>& A, int K) {
        //credit to lee215
        int i = 0, res = 0;
        std::unordered_map<int, int> count;
        for (int j = 0; j < A.size(); ++j) {
            if (!count[A[j]]++)
                K--;
            while (K < 0) {
                if (!--count[A[i]])
                    K++;
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }

public:
    int subarraysWithKDistinct(std::vector<int>& A, int K) {
        return atMostK(A, K) - atMostK(A, K - 1);
    }
};