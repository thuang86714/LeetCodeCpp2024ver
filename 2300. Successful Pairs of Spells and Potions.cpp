#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        //TC O(max(nlogn, m*logn)), where m is spells.size(), n is potions.size(), SC O(1)
        std::sort(potions.begin(), potions.end());
        std::vector<int> pairs;
        for(int &spell:spells){
            int left = 0, right = potions.size() - 1;
            while(left <= right){
                int mid = left + (right - left)/2;
                if(1LL *spell*potions[mid] >= success){//this potion would succed, go left to find the potion with less strength
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            pairs.push_back(potions.size() - left);//all potions on the right of the left potion(inclusive) would be successful 
        }
        return pairs;
    }
};