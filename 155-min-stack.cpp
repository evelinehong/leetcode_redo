struct node{
    int val;
    int minimum;
};
class MinStack {

public:
    /** initialize your data structure here. */
    vector<node> mstack;
    MinStack() {
        
    }
    
    void push(int x) {
        if (!mstack.empty()) mstack.push_back({x, min(mstack.back().minimum, x)});
        else mstack.push_back({x,x});
    }
    
    void pop() {
        if (!mstack.empty()) mstack.pop_back();
    }
    
    int top() {
        return mstack.back().val;
    }
    
    int getMin() {
        return mstack.back().minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */