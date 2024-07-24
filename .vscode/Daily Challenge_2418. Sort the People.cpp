#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
class Solution {
public:
    std::vector<std::string> sortPeople(std::vector<std::string>& names,
                                        std::vector<int>& heights) {
        //TC O(nlogn), SC O(n)
        std::unordered_map<int, std::string> heightNameMap;
        for (int i = 0; i < names.size(); i++) {
            heightNameMap[heights[i]] = names[i];
        }
        std::sort(heights.begin(), heights.end(), std::greater<int>());

        std::vector<std::string> result;
        for (const int& height : heights) {
            result.push_back(heightNameMap[height]);
        }
        return result;
    }
};