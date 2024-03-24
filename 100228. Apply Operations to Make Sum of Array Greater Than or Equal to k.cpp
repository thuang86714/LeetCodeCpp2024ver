class Solution {
public:
    int minOperations(int k) {
        if(k==1) return 0;
        
        int minTime = k-1;
        for(int i=1; i<=k; i++){
            auto d = k/i;
            if(k%i!=0){
                minTime = min(minTime, i-1 + d );
            }else{
                minTime = min(minTime, i-1 + d-1);
            }
        }
        
        return minTime;
    }
};