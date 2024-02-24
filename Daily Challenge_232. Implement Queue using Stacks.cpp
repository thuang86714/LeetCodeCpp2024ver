#include <stack>
using namespace std;


class MyQueue {
private:
    //stack LIFO
    stack<int> intStack1, intStack2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        intStack1.push(x);
    }
    
    int pop() {
        int ans = peek();
        intStack2.pop();
        return ans;
    }
    
    int peek() {
        if(intStack2.empty()){
            while(intStack1.size()){
                intStack2.push(intStack1.top());
                intStack1.pop();
            }
        }
        return intStack2.top();
    }
    
    bool empty() {
        return intStack1.empty() && intStack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */