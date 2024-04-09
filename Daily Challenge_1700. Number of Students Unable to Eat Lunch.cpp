#include <vector>

class Solution {
public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
        //credit to lee215, TC O(n), SC O(1)
        std::vector<int> preferenceCount(2, 0);
        int idx, len = students.size();
        for(const int &preference:students){
            preferenceCount[preference]++;
        }
        for(idx = 0; idx < len && preferenceCount[sandwiches[idx]] > 0; idx++){
            preferenceCount[sandwiches[idx]]--;
        }
        return len - idx;
    }
};