class MinHeap {
    vector<int> heap;
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
        int i = 1;
        int returnVal = heap[i];
        heap[i] = heap[heap.size()-1];
        heap.pop_back();
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

        return returnVal;
    }

    int top() {
        if(heap.size()<2) return -1;
        return heap[1];
    }

    void heapify(const vector<int>& arr) {
        heap.clear();
        heap.push_back(0);
        for(int each:arr){
            push(each);
        }
    }
};
