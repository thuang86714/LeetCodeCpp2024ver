#include <vector>

class StockSpanner {
private:
    std::vector<std::pair<int, int>> priceVector;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        //TC O(n)
        int span = 1;
        for(int i = priceVector.size() - 1; i >= 0; i--){
            if(priceVector[i].first <= price){
                span += priceVector[i].second;
                priceVector.pop_back();
            }else{
                break;
            }
        }
        priceVector.push_back({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */