#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Solution {
private:
    std::unordered_map<int, std::vector<int>> graph;
    void buildGraph(std::vector<std::vector<int>>& edges){
        for(auto &edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }
public:
    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        //BFS
        if(source == destination){
            return true;
        }
        std::unordered_set<int> visitedSet;
        visitedSet.insert(source);

        buildGraph(edges);
        if(!graph[source].size() || !graph[destination].size()){
            return false;
        }

        std::queue<int> toVisitQueue;
        toVisitQueue.push(source);
        
        while(!toVisitQueue.empty()){
            int curVertex = toVisitQueue.front();
            toVisitQueue.pop();

            for(int &nextVertex: graph[curVertex]){
                if(nextVertex == destination){
                    return true;
                }
                if(!visitedSet.count(nextVertex)){
                    visitedSet.insert(nextVertex);
                    toVisitQueue.push(nextVertex);
                }
            }
        }
        return false;
    }
};