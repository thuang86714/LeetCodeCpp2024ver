#include <vector>
using namespace std;


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //TC O(n), SC O(1)
        if(n == 0){
            return true;
        }
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 0 && (i == 0 || !flowerbed[i - 1]) &&(i == flowerbed.size() - 1 || !flowerbed[i + 1])){
                flowerbed[i] = 1;
                n--;
                if(n == 0){
                    return true;
                }
            }
        }
        return false;
    }
};