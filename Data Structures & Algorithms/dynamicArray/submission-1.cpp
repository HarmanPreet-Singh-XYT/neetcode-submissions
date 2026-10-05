class DynamicArray {
    int capacity;
    int* arr;
    int length;
public:

    DynamicArray(int capacity) {
        arr = new int[capacity];
        this->capacity = capacity;
        length = 0;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(length == capacity){
            resize();
        }
        arr[length] = n;
        length++;
    }

    int popback() {
        if(length > 0){
            length--;
        }
        return arr[length];
    }

    void resize() {
        capacity *=2;
        int* newArr = new int[capacity];
        for(int x = 0;x<=length;x++){
            newArr[x] = arr[x];
        }
        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};
