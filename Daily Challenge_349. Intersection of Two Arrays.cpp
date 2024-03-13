#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        //TC O(n), SC O(m+n)
        std::unordered_set<int> dict{nums1.begin(), nums1.end()}, dict2;
        std::vector<int> res;
        for(int &num:nums2){
            if(dict.count(num) && !dict2.count(num)){
                res.push_back(num);
                dict2.insert(num);
            }
        }
        return res;
    }
};