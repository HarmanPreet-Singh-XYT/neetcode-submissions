class MinHeap {
    vector<int> heap;
    void bubbleDown(int i){
        while(i*2<heap.size()){
            int minIdx = i*2;
            if(heap.size()-1 >= i*2+1 && heap[minIdx] > heap[i*2+1]){
                minIdx = i*2+1;
            }
            int tempIdx = minIdx;
            if(heap[i] > heap[minIdx]){
                swap(heap[i],heap[minIdx]);
                i = tempIdx;
            }else{
                break;
            }
        }
    }
public:
    MinHeap() {
        heap.push_back(0);
    }

    void push(int val) {
        heap.push_back(val);
        int i = heap.size()-1;
        int p = i/2;

        while(heap[p] > heap[i] && i > 1){
            swap(heap[p],heap[i]);
            i = p;
            p = i/2;
        }
    }

    int pop() {
        if(heap.size()<2) return -1;
        if (heap.size() == 2) {
            int root = heap.back();
            heap.pop_back();
            return root;
        }
        int returnVal = heap[1];
        heap[1] = heap[heap.size()-1];
        heap.pop_back();
        bubbleDown(1);

        return returnVal;
    }

    int top() {
        if(heap.size()<2) return -1;
        return heap[1];
    }

    void heapify(const vector<int>& arr) {
        heap.clear();
        heap.push_back(0);
        heap.insert(heap.end(),arr.begin(),arr.end());
        for(int x = (heap.size()-1);x>=1;x--){
            bubbleDown(x);
        }
    }
};
