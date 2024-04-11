#include <vector>

class Solution {
private:
    void findAllConnected(std::vector<std::vector<int>>& isConnected, std::vector<int> &visited, int idx){
        for(int j = 0; j < isConnected.size(); j++){
            if(isConnected[idx][j] && !visited[j]){
                visited[j] = 1;
                findAllConnected(isConnected, visited, j);
            }
        }
    }
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        //credit to vindo23, TC O(n), SC O(n)
        std::vector<int> visited(isConnected.size(), 0);
        int provinceCount = 0;
        for(int i = 0; i < isConnected.size(); i++){
            if(!visited[i]){
                findAllConnected(isConnected, visited, i);
                provinceCount++;
            }
        }
        return provinceCount;
    }
};