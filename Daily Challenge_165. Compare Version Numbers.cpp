#include <string>

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        //TC O(n), SC O(1)
        int idx1 = 0, idx2 = 0;
        while(idx1 < version1.size() || idx2 < version2.size()){
            std::string tempStr1 = "", tempStr2 = "";
            while(idx1 < version1.size() && version1[idx1] != '.'){
                tempStr1 += version1[idx1];
                idx1++;
            }
            int tempInt1;
            if(tempStr1 == ""){
                tempInt1 = 0;
            }else{
                tempInt1= std::stoi(tempStr1);
            }

            while(idx2 < version2.size() && version2[idx2] != '.'){
                tempStr2 += version2[idx2];
                idx2++;
            }
            int tempInt2;
            if(tempStr2 == ""){
                tempInt2 = 0;
            }else{
                tempInt2 = std::stoi(tempStr2);
            }
            
            if(tempInt1 > tempInt2){
                return 1;
            }else if(tempInt1 < tempInt2){
                return -1;
            }
            if(idx1 < version1.size()){
                idx1++;
            }
            if(idx2 < version2.size()){
                idx2++;
            }
        }
        return 0;
    }
};