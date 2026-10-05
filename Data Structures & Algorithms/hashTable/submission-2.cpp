class Node{
    public:
    int key;
    int val;
    Node* next;
    Node(int key, int value) : key(key), val(value), next(nullptr) {}
};
class HashTable {
    vector<Node*> table;
    int size;
    int capacity;
    int hashFunction(int key){
        return key%capacity;
    }
public:
    HashTable(int capacity) {
        this->capacity = capacity;
        size = 0;
        table.resize(capacity,nullptr);
    }

    void insert(int key, int value) {
        int hashedKeyIndex = hashFunction(key);
        if(table[hashedKeyIndex]){
            while(table[hashedKeyIndex]){
                if(table[hashedKeyIndex]->key == key){
                    table[hashedKeyIndex]->val = value;
                    return;
                }
                hashedKeyIndex++;
            }
        }
        Node* node = new Node(key,value);
        table[hashedKeyIndex] = node;
        size++;
        if(size>=(capacity/2)) resize();
    }

    int get(int key) {
        int hashedKeyIndex = hashFunction(key);
        while(table[hashedKeyIndex]){
            if(table[hashedKeyIndex]->key == key){
                return table[hashedKeyIndex]->val; 
            }
            hashedKeyIndex++;
        }
        return -1;
    }

    bool remove(int key) {
        int hashedKeyIndex = hashFunction(key);
        while(table[hashedKeyIndex]){
            if(table[hashedKeyIndex]->key == key){
                table[hashedKeyIndex] = nullptr;
                size--;
                return true;
            }
            hashedKeyIndex++;
        }
        return false;
    }

    int getSize() const {
        return this->size;
    }

    int getCapacity() const {
        return this->capacity;
    }

    void resize() {
        vector<Node*>oldTable = table;
        vector<Node*> newTable(capacity*2,nullptr);
        table = newTable;
        size = 0;
        capacity = capacity*2;
        for(int i = 0; i<oldTable.size();i++){
            if(oldTable[i]){
                insert(oldTable[i]->key,oldTable[i]->val);
            }
        }
    }
};
