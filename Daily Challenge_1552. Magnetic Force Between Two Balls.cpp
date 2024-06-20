#include <vector>
#include <algorithm>

class Solution {
private:
    int countNode(std::vector<int>& position, int curDist){
        //credit to alanlzl, O(NlogM), where M = max(position) - min(position), Space complexity: O(1)
        int ans = 1, cur = position[0];
        for(int i = 1; i < position.size(); i++){
            if(position[i] - cur >= curDist){
                ans++;
                cur = position[i];
            }
        }
        return ans;
    }
public:
    int maxDistance(std::vector<int>& position, int m) {
        std::sort(position.begin(), position.end());
        int left = 0, right = position.back() - position.front();

        while(left <= right){
            int mid = (right - left)/2 + left;
            if(countNode(position, mid) >= m){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return right;
    }
};