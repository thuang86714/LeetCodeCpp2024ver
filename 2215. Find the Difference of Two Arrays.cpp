#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        //TC O(n), SC O(n)
        std::unordered_set<int> dict1{nums1.begin(), nums1.end()};
        std::unordered_set<int> dict2{nums2.begin(), nums2.end()};
        std::vector<int> list1, list2;
        for(auto &num:dict1){ 
            if(dict2.find(num) == dict2.end()){
                list1.push_back(num);
            }
        }
        for(auto &num:dict2){
            if(dict1.find(num) == dict1.end()){
                list2.push_back(num);
            }
        }
        return {list1, list2};
    }
};