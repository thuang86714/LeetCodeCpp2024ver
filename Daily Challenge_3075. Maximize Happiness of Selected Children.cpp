#include <vector>
#include <algorithm>

class Solution {
public:
    long long maximumHappinessSum(std::vector<int>& happiness, int k) {
        long long ans = 0;
        int childCount = 0, idx = happiness.size() - 1;
        std::sort(happiness.begin(), happiness.end());
        while(k > 0 && idx >= 0){
            if(happiness[idx] - childCount >= 0){
                ans += happiness[idx] - childCount;
            }else{//meaning that we've reached the element that woudl give us max(given k)
                break;
            }
            idx--;
            k--;
            childCount++;
        }
        return ans;
    }
};