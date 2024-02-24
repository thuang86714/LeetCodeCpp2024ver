#include <unordered_set>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        //credit to Necctor(under the post of avarughe)
        vector<bitset<26>> charCount; 
        for (auto s : arr) {
            bitset<26> a;
            for (char c : s) {
                a.set(c - 'a');
            }
            if (a.count() == s.size()){
                charCount.push_back(a);
            }
        }
        return findMax(charCount, bitset<26>(), 0);
    }
    
    int findMax(vector<bitset<26>>& charCount, bitset<26> bs, int index) {
        int res = bs.count();
        for (int i = index; i < charCount.size(); i++) {
            if (!(charCount[i] & bs).any()){ 
                res = max(res, findMax(charCount, bs | charCount[i], i+1));
            }
        }
        return res;
    }
};


class Solution {
//credit to avarughe
public:
    int maxLength(vector<string>& arr, string str = "", int idx = 0) {
        //Use set to check if the string contains all unique characters
        unordered_set<char>visited(str.begin(), str.end());
        if(visited.size() != str.size()){
            return 0;
        }
        int res = str.size();
        for(int i = idx; i < arr.size(); i++){
            res = max(res, maxLength(arr, str + arr[i], i + 1));
        }
        return res;
    }
};