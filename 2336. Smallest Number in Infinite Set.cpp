#include <set>

class SmallestInfiniteSet {
private:
    int cur = 1;
    std::set<int> added;
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(!added.empty()){
            int res = *added.begin();
            added.erase(added.begin());
            return res;
        }
        return cur++;
    }
    
    void addBack(int num) {
        if(num < cur){
            added.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */