#include <algorithm>
#include <vector>
class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        //k has an interval [1, *max_element(piles.begin(), miles.end())];
        //need to find the k that KoKo could cosume all bananas just in time
        //TC O(n*logm), where n is the len of piles and m is the max number in piles, SC O(1)
        int left = 1, right = *std::max_element(piles.begin(), piles.end());
        while(left <= right){
            long long int k = left + (right - left)/2;
            long long int sumTime = 0;
            for(int &banana:piles){
                sumTime += (banana + k -1)/k;//use ceil may not get expected result
            }
            if(sumTime <= h){//KoKo eats too fast, needs to slow down
                right = k - 1;
            }else if(sumTime > h){//KoKo eats too slow, needs to speed up
                left = k + 1;
            }
        }
        return left;
    }
};