#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) {
        std::vector<std::pair<int, int>> numFreqPairVec;
        std::unordered_map<int, int> numFreqMap;
        for (const int& num : nums) {
            numFreqMap[num]++;
        }

        for (const auto& item : numFreqMap) {
            numFreqPairVec.push_back({item.second, item.first});
        }

        std::sort(
            numFreqPairVec.begin(), numFreqPairVec.end(),
            [&](const std::pair<int, int>& i, const std::pair<int, int>& j) {
                if (i.first != j.first) {
                    return i.first < j.first;
                }
                return i.second > j.second;
            });

        std::vector<int> result;
        for (const auto& pair : numFreqPairVec) {
            for (int i = 0; i < pair.first; i++) {
                result.push_back(pair.second);
            }
        }
        return result;
    }
};