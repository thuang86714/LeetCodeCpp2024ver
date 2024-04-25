#include <string>
#include <queue>
#include <unordered_set>

class Solution {
private:
    inline char increaseChar(char cur){
        if(cur == '9'){
            return '0';
        }
        return cur + 1;
    }

    inline char decreaseChar(char cur){
        if(cur == '0'){
            return '9';
        }
        return cur - 1;
    }
public:
    int openLock(std::vector<std::string>& deadends, std::string target) {
        //BFS
        std::unordered_set<std::string> deadendsSet(deadends.begin(), deadends.end()), visitedSet{"0000"};
        if(deadendsSet.count("0000")){
            return -1;
        }
        int count = 0;
        std::queue<std::string> toVisitQueue;
        toVisitQueue.push("0000");

        while(!toVisitQueue.empty()){
            int curSize = toVisitQueue.size();
            while(curSize--){
                std::string curString = toVisitQueue.front();
                toVisitQueue.pop();

                if(curString == target){
                    return count;
                }

                for(char &c: curString){
                    c = increaseChar(c);
                    if(!deadendsSet.count(curString) && !visitedSet.count(curString)){
                        toVisitQueue.push(curString);
                        visitedSet.insert(curString);
                    }

                    c = decreaseChar(decreaseChar(c));
                    if(!deadendsSet.count(curString) && !visitedSet.count(curString)){
                        toVisitQueue.push(curString);
                        visitedSet.insert(curString);
                    }
                    c = increaseChar(c);
                }
            }
            count++;
        }
        return -1;
    }
};