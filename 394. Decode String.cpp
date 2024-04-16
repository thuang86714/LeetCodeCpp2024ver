#include <string>

class Solution {
private:
    std::string buildString(const std::string curString, int &idx){
        std::string result = "";
        while(idx < curString.size() && curString[idx] != ']'){
            if(!isdigit(curString[idx])){
                result += curString[idx];
                idx++;
            }else{
                int repeat = 0;
                while(idx < curString.size() && isdigit(curString[idx])){
                    repeat = repeat*10 + curString[idx] - '0';
                    idx++;
                }   
                idx++;//skip '['
                std::string tempString = buildString(curString, idx);
                idx++;//skip ']'
                while(repeat){
                    repeat--;
                    result += tempString;
                }
            }
        }
        return result;
    }
public:
    std::string decodeString(std::string s) {
        int i = 0;
        return buildString(s, i);
    }
};