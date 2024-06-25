#include <vector>
#include <queue>

class Solution {
public:
    int minKBitFlips(std::vector<int>& nums, int k) {
        //credit to votrubac, solution2, TC O(n), SC O(n)
        int res = 0;
        std::queue<int> flipTrackQueue;
        for(int idx = 0; idx < nums.size(); idx++){
            if(nums[idx] != (flipTrackQueue.size()%2? 0 : 1)){
                res++;
                //the lst idx would be affected by cur sliding window
                flipTrackQueue.push(idx + k - 1);
            }
            //meaning the sliding window is moving out of this range, the old bit would not be fliped anymore
            if(flipTrackQueue.size() != 0 && flipTrackQueue.front() <= idx){
                flipTrackQueue.pop();
            }
        }
        if(flipTrackQueue.size() == 0){
            return res;
        }
        //meaning there's still 0 in the array
        return -1;
    }
};

class Solution {
public:
    int minKBitFlips(std::vector<int>& nums, int k) {
        //credit to votrubac, TC O(n), SC O(1)
        //we can track the total number of flips, and use the source array to mark flips with negative values.
        int res = 0, flipRemainedCount = 0;
        for(int idx = 0; idx < nums.size(); idx++){
            if(nums[idx] == flipRemainedCount%2){
                if(idx > nums.size() - k){
                    return -1;
                }
                res++;
                flipRemainedCount++;
                nums[idx] -= 2;
            }
            if(idx >= k - 1 && nums[idx - k + 1] < 0){
                flipRemainedCount++;
                nums[idx - k + 1] += 2;
            }
        }
        return res;
    }
};