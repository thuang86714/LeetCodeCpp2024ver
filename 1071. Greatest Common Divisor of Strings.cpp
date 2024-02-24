#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        //credit to vishnoi29
        if(str1 + str2 == str2 + str1){
            return str1.substr(0, __gcd(str1.size(), str2.size()));
        }else{
            return "";
        }
    }
};