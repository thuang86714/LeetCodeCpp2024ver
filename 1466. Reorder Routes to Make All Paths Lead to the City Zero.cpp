#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

class Solution {
private:
    std::unordered_map<int, std::unordered_set<int>> directedGraph;
    std::unordered_map<int, std::vector<int>> unDirectedGraph;
    void buildGraph(std::vector<std::vector<int>>& connections){
        for(auto connection:connections){
            unDirectedGraph[connection[0]].push_back(connection[1]);
            unDirectedGraph[connection[1]].push_back(connection[0]);
            directedGraph[connection[1]].insert(connection[0]);
        }
    }
public:
    int minReorder(int n, std::vector<std::vector<int>>& connections) {
        //BFS, TC O(n+E), SC O(n+E)
        buildGraph(connections);
        std::queue<int> toVisitQueue;
        std::unordered_set<int> visitedSet;
        toVisitQueue.push(0);
        int reorderCount = 0;
        while(!toVisitQueue.empty()){
            int curLevelSize = toVisitQueue.size();
            for(int i = 0; i < curLevelSize; i++){
                int curNode = toVisitQueue.front();
                visitedSet.insert(curNode);
                toVisitQueue.pop();
                for(int nextNode:unDirectedGraph[curNode]){
                    if(visitedSet.count(nextNode)){
                        continue;
                    }
                    if(!directedGraph[curNode].count(nextNode)){
                        reorderCount++;
                    }
                    toVisitQueue.push(nextNode);
                }
            }
        }
        return reorderCount;
    }
};