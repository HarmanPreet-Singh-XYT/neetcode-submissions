class DynamicArray {
    int capacity;
    int size;
    int* arr;
public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(size+1 > capacity){
            resize();
        }
        arr[size] = n;
        size++;
    }

    int popback() {
        return arr[--size];
    }

    void resize() {
        int* resizedArr = new int[capacity*2];
        for(int x = 0;x<size;x++){
            resizedArr[x] = arr[x];
        }
        arr = resizedArr;
        capacity *=2;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
