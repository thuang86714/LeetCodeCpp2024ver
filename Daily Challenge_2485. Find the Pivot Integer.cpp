class Solution {
public:
    int pivotInteger(int n) {
        //binary search, TC O(logn), SC O(1)
        int left = 1, right = n;
        while(left <= right){
            int pivot = left + (right - left)/2;
            int leftSum = (1 + pivot)*pivot/2;//sum of all number on the left of pivot and pivot itself
            int rightSum = (pivot + n)*(n - pivot + 1)/2;//sum of all number on the right of pivot and pivot itself
            if(leftSum == rightSum){//given there is at most one solution
                return pivot;
            }else if(leftSum > rightSum){
                right = pivot - 1;
            }else{
                left = pivot + 1;
            }
        }
        return -1;
    }
};