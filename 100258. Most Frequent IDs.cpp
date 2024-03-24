#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<long long> ans;
        
        unordered_map<long long, long long> numFreqMap; // key is num, value is freq
        map<long long, unordered_set<long long>> freqNumMap;  // key is freq, value is num hash table
        long long maxFreq = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(!numFreqMap.count(nums[i])){
                numFreqMap[nums[i]] = freq[i];    
                freqNumMap[freq[i]].insert(nums[i]);
                maxFreq = max(maxFreq, (long long)freq[i]);
            }else{
                auto prevFreq = numFreqMap[nums[i]];
                auto curFreq = prevFreq+freq[i];
                numFreqMap[nums[i]] = curFreq;
                freqNumMap[prevFreq].erase(nums[i]);
                freqNumMap[curFreq].insert(nums[i]);
                
                if(freqNumMap[prevFreq].size() == 0){
                    freqNumMap.erase(prevFreq);
                    maxFreq = 0;
                }
                
                maxFreq = max(maxFreq, freqNumMap.rbegin()->first);
                
            }
            
            ans.push_back(maxFreq);
            
        }
        return ans;
    }
};