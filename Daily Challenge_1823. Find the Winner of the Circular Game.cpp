#include <queue>
class Solution {
public:
    int findTheWinner(int n, int k) {
        /*
        TC O(n), SC O(1)
        credit to hritesh_bhardwaj
        Intution : If I have the winner for 'n-1' and 'k'.
        I can find the winner for 'n' and 'k' by moving on to the next kth
        person (i.e. f(n) = f(n-1)+k).
        */
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = (ans + k) % i;
        }
        return ans + 1;
    }
};


class Solution {
public:
    int findTheWinner(int n, int k) {
        //TC O(n*k), SC O(n)
        std::queue<int> circleQueue;
        for(int i = 1; i <= n; i++){
            circleQueue.push(i);
        }

        while(circleQueue.size() > 1){
            int curK = k, lastNode = 0;
            while(curK > 0){
                if(lastNode != 0){
                    circleQueue.push(lastNode);
                }
                lastNode = circleQueue.front();
                circleQueue.pop();
                curK--;
            }
        }
        return circleQueue.front();
    }
};