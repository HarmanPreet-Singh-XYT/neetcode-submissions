class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(int x:nums){
            minHeap.push(x);
            if(minHeap.size() > kth){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>kth){
            minHeap.pop();
        }
        return minHeap.top();
    }
};