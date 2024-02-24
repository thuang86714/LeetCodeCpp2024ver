#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //credit to caihao0727mail, TC O(n), SC O(1)
        for(int i = 0; i<nums.size(); i++){
            while(nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i<nums.size() ; i++){
            if(nums[i] != i + 1){
                return {nums[i], i + 1};
            }
        }
        return {};
    }
};


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //TC O(n), SC O(n)
        vector<int> ans;
        unordered_set<int> numCount;
        for(int i = 1; i <= nums.size(); i++){
            numCount.insert(i);
        }
        for(int num:nums){
            if(numCount.count(num)){
                numCount.erase(num);
            }else{
                ans.push_back(num);
            }
        }
        for(int num:numCount){
            ans.push_back(num);
        }
        return ans;
    }
};