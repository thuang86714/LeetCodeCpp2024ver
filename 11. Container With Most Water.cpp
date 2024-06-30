#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        // two pointer, TC O(n), SC O(1)
        int left = 0, right = height.size() - 1;
        long curWater = 0;
        while (left < right) {
            int curHeight = std::min(height[left], height[right]);
            int curWidth = right - left;
            curWater = std::max(long(curWater), long(curHeight * curWidth));
            while (left < right && height[left] <= curHeight) {
                left++;
            }
            while (left < right && height[right] <= curHeight) {
                right--;
            }
        }
        return curWater;
    }
};
