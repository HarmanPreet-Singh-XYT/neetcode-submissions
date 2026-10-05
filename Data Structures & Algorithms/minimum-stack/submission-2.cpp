class MinStack {
    stack<int> st;
    stack<int> minStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(!minStack.empty() && val > minStack.top()){
            val = minStack.top();
        }
        minStack.push(val);
    }
    
    void pop() {
        st.pop();
        minStack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
