#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

class Solution {
    private:
        std::vector<std::vector<int>> directedGraphVec;
        void buildGraph(std::vector<std::vector<int>>& edges){
            for(const auto &edge: edges){
                directedGraphVec[edge[1]].push_back(edge[0]);
            }
        }
    public:
        std::vector<std::vector<int>> getAncestors(int n, std::vector<std::vector<int>>& edges) {
            directedGraphVec = std::vector<std::vector<int>>(n);
            std::vector<std::vector<int>> ansVec(n);
            buildGraph(edges);
    
            for(int i = 0; i < n; i++){
                std::unordered_set<int> visitedSet;
                std::queue<int> toVisitQueue;
                toVisitQueue.push(i);
    
                while(!toVisitQueue.empty()){
                    int curNode = toVisitQueue.front();
                    toVisitQueue.pop();
    
                    for(const auto &ancestor: directedGraphVec[curNode]){
                        if(!visitedSet.count(ancestor)){
                            visitedSet.insert(ancestor);
                            ansVec[i].push_back(ancestor);
                            toVisitQueue.push(ancestor);
                        }
                    }
                }
                std::sort(ansVec[i].begin(), ansVec[i].end());
            }
            return ansVec;
        }
    };

/*
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> in(n);
        vector<vector<int>> res(n);

        for(auto& e : edges){
            int a = e[0], b = e[1];
            graph[a].push_back(b);
            in[b]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++)
            if(in[i] == 0) q.push(i);

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto next : graph[curr]){                
                res[next].push_back(curr);
                res[next].insert(res[next].end(), res[curr].begin(), res[curr].end());
                sort(res[next].begin(), res[next].end());
                res[next].erase(unique(res[next].begin(), res[next].end()), res[next].end());

                in[next]--;
                if(in[next] == 0)
                    q.push(next);
            }
        }

        // for(int i = 0; i < n; i++)
        //     sort(res[i].begin(), res[i].end());

        return res;
    }
};
*/