class MinStack {
private:
    vector<int> st;
    vector<int> minSt = {INT_MAX};
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.emplace_back(x);
        if (minSt[minSt.size()-1] >= x) minSt.emplace_back(x);
    }
    
    void pop() {
        if ((int)st.size() == 0) return;
        if (st[st.size()-1] == minSt[minSt.size()-1]) minSt.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st[st.size()-1];
    }
    
    int getMin() {
        return minSt[minSt.size()-1];
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
