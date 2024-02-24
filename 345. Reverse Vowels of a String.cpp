class Solution {
private:
    bool isVowel(char ch){
        char temp = tolower(ch);
        if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u'){
            return true;
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r){
            while(l < r && !isVowel(s[l])){
                l++;
            }
            while(l < r && !isVowel(s[r])){
                r--;
            }
            swap(s[l++], s[r--]);
        }
        return s;
    }
};