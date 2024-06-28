#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    std::vector<double> res;
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> map;
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries) {
        buildMap(equations, values);
        
        for(auto &q:queries){
            std::unordered_set<std::string> visited(map.size());
            double ans = findFloat(q[0], q[1], visited);
            res.push_back(ans);
        }
        return res;
    }
private:
    void buildMap(std::vector<std::vector<std::string>>& equations, std::vector<double>& values){
        for(int i = 0; i < equations.size(); i++){
            map[equations[i][0]].push_back({equations[i][1], values[i]});
            map[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        return;
    }
    double findFloat(std::string start, std::string end, std::unordered_set<std::string> &visited){
        if(map.find(start) == map.end() || map.find(end) == map.end()){
            return -1;
        }

        if(start == end){
            return 1;
        }

        for(auto &next:map[start]){
            if(visited.count(next.first)){
                continue;
            }
            visited.insert(next.first);
            double res = findFloat(next.first, end, visited);
            if(res != -1){
                return res*next.second;
            }
        }
        return -1;
    }
};