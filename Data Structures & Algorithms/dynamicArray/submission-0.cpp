class DynamicArray {
    int* arr;
    int currIndex;
    int capacity;
public:

    DynamicArray(int capacity) {
        this->arr = new int[capacity];
        this->currIndex = 0;
        this->capacity = capacity;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(currIndex == capacity){
            resize();
        }
        arr[currIndex] = n;
        currIndex++;
    }

    int popback() {
        if(currIndex > 0){
            this->currIndex--;
        }
        return arr[currIndex];
    }

    void resize() {
        capacity *=2;
        int* newArr = new int[capacity];
        for(int x = 0; x<= currIndex; x++){
            newArr[x] = arr[x];
        }
        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return this->currIndex;
    }

    int getCapacity() {
        return this->capacity;
    }
};
