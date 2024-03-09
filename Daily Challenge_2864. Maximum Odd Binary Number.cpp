#include <string>

class Solution {
public:
    std::string maximumOddBinaryNumber(std::string s) {
        //TC O(n), SC O(1)
        int oneCount = 0, zeroCount = 0;
        for(auto num:s){
            if(num == '1'){
                oneCount++;
            }else{
                zeroCount++;
            }
        }
        std::string ans = std::string(oneCount - 1, '1') + std::string(zeroCount, '0') + "1";
        return ans;
    }
};