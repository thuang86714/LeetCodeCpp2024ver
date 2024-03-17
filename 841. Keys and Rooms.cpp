#include <vector>
#include <unordered_set>

class Solution {
private:
    std::unordered_set<int> visited;
    std::vector<std::vector<int>> allRoom;
    void unlockRoom(int curRoomNum){
        if(!allRoom[curRoomNum].size()){//termination condition, prevent loop
            return;
        }
        
        std::vector<int> tempVec = allRoom[curRoomNum];
        allRoom[curRoomNum].clear();
        for(int &key:tempVec){
            if(!visited.count(key)){
                visited.insert(key);
                unlockRoom(key);
            }
        }
    }
public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
        //DFS, TC O(n), SC O(n)
        allRoom = rooms;
        visited.insert(0);
        unlockRoom(0);
        return visited.size() == rooms.size();
    }
};