class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        vector<int> arr;
        int size = q.size();
        while(size>0){
            int topElem = q.front();
            arr.push_back(q.front());
            size--;
            q.pop();
            if(size>0){
                q.push(topElem);
            }
        }
        return arr.back();
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */