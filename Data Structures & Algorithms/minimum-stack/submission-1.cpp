class MinStack {
    stack<int> st;
public:
    MinStack() {
        st = {};
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> tmp = st;
        int min = st.top();
        while(!tmp.empty()){
            int top = tmp.top();
            if(top < min){
                min = top;
            }
            tmp.pop();
        }
        return min;
    }
};
