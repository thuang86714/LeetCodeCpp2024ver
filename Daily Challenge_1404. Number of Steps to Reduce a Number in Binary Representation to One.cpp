#include <string>

class Solution {
public:
    int numSteps(std::string s) {
        //TC O(n), SC O(1)
        int step = 0, idx = s.size() - 1;
        while(idx >= 0){
            if(s[idx] == '0'){
                step++;
                idx--;
            }else if(s[idx] == '1'){
                if(idx == 0){
                    break;
                }
                s[idx] = '0';
                if(idx > 0){
                    s[idx - 1] += 1;
                }
                step++;
            }else if(s[idx] == '2'){
                s[idx] = '0';
                if(idx > 0){
                    s[idx - 1] += 1;
                }
            }
        }
        
        return step;
    }
};