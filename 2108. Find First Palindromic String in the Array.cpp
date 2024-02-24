inline <string>
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string str: words){
            int i = 0, j = str.size() - 1;
            while(str[i] == str[j]){
                if(i >= j){
                    return str;
                }
                i++;
                j--;
            }
        }
        return "";
    }
};