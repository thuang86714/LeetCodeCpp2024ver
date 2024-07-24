#include <vector>
#include <algorithm>

struct numIdxCombo {
    int oldNum, newNum, idx;
};
class Solution {
public:
    std::vector<int> sortJumbled(std::vector<int>& mapping,
                                 std::vector<int>& nums) {
        std::vector<numIdxCombo> numIdxSlice;
        for (int curIdx = 0; curIdx < nums.size(); ++curIdx) {
            int num = nums[curIdx];
            int cur = num, next = 0, digit = 1;
            if (cur == 0) {
                numIdxSlice.push_back({num, mapping[0], curIdx});
                continue;
            }

            while (cur > 0) {
                next = mapping[cur % 10] * digit + next;
                cur /= 10;
                digit *= 10;
            }
            numIdxSlice.push_back({num, next, curIdx});
        }
        std::sort(numIdxSlice.begin(), numIdxSlice.end(),
                  [](const numIdxCombo& a, const numIdxCombo& b) {
                      if (a.newNum == b.newNum)
                          return a.idx < b.idx;
                      return a.newNum < b.newNum;
                  });

        std::vector<int> result;
        for (const auto& combo : numIdxSlice) {
            result.push_back(combo.oldNum);
        }

        return result;
    }
};