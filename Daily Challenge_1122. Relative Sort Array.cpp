#include <map>
#include <vector>

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        //TC O(nlogn), SC O(n)
        std::map<int, int> numCountMap;
        for(const int &num:arr1){
            numCountMap[num]++;
        }
        int idx = 0;
        for(const int &num:arr2){
            while(numCountMap[num] > 0){
                arr1[idx] = num;
                idx++;
                numCountMap[num]--;
            }
        }

        for(auto &it:numCountMap){
            while(it.second > 0){
                arr1[idx] = it.first;
                idx++;
                it.second--;
            }
        }
        return arr1;
    }
};