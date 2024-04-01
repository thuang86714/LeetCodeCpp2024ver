#include <vector>
#include <algorithm>

class Solution {
private:
    static bool customCompare(std::vector<int> &i, std::vector<int> &j){
        return i[1] < j[1];
    }
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), customCompare);
        int count = 0, curBack = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if(curBack > intervals[i][0]){
                count++;
            }else{
                curBack = intervals[i][1];
            }
        }

        return count;
    }
};