#include <vector>
#include <algorithm>

class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        //TC O(nlogn), SC O(1)
        int ans = 0, left = 0, right = people.size() - 1;
        std::sort(people.begin(), people.end());
        while(left <= right){
            if(people[left] + people[right] <= limit){
                left++;
            }
            right--;
            ans++;
        }
        return ans;
    }
};