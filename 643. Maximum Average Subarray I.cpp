#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //TC O(n), SC O(1)
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        int temp = sum;
        for(int i = 0; i < nums.size() - k; i++){
            temp -= nums[i];
            temp += nums[i + k];
            sum = max(sum, temp);
        }
        return sum/double(k);
    }
};