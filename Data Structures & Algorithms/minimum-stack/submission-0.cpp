class MinStack {
    vector<int> st;
public:
    MinStack() {
        st = {};
    }
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        int min = st[0];
        for(int x = 0;x<st.size();x++){
            if (st[x] < min){
                min = st[x];
            }
        }
        return min;
    }
};
