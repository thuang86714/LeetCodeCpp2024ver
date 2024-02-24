class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        //TC O(n), SC O(1)
        int ans = 0, cur = 0;
        for(int g:gain){
            cur += g;
            ans = max(ans, cur);
        }
        return ans;
    }
};