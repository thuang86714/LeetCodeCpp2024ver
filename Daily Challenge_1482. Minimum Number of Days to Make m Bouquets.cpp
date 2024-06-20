#include <vector>
#include <algorithm>

class Solution {
private:
    bool canMakeBouquets(int days, const std::vector<int>& bloomDay, const int &m, const int &k){
        int curBouquet = 0, curFlower = 0;
        for(const int &bloom : bloomDay){
            if (bloom <= days) {
                curFlower++;
                if (curFlower == k) {
                    curFlower = 0;
                    curBouquet++;
                }
            }else{
                curFlower = 0;
            }
        }
        return curBouquet >= m;
    }
public:
    int minDays(std::vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()/m < k){
            return -1;
        }
        int left = *std::min_element(bloomDay.begin(), bloomDay.end());
        int right = *std::max_element(bloomDay.begin(), bloomDay.end());
        while(left <= right){
            int mid = (right - left)/2 + left;
            if(canMakeBouquets(mid, bloomDay, m, k)){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};