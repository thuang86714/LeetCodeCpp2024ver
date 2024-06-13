#include <vector>
#include <algorithm>

class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
        //TC O(nlogn), SC O(1)-->counting sort could reach TC O(n), SC O(1)
        int ans = 0;
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());
        for(int idx = 0; idx < seats.size(); idx++){
            ans += std::abs(seats[idx] - students[idx]);
        }
        return ans;
    }
};