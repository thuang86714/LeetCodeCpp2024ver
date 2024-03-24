#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            int count = 0;
            for(int &num: nums){
                if(num <= mid){
                    count++;
                }
            }
            /*
            //means the number of elements in the lower half 
            (1 to mid) is less than or equal to what it should be 
            in a scenario without duplicates. 
            Hence, the duplicate must be in the upper half, 
            so the search continues with left = mid + 1
            */
            if(count <= mid){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return left;
    }
};