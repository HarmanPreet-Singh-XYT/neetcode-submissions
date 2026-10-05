class LRUCache {
    vector<pair<int,int>> hash;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        int i = 0;
        for(pair p: hash){
            if(p.first == key){
                hash.push_back(hash[i]);
                hash.erase(hash.begin()+i);
                return p.second;
            }
            i++;
        }
        return -1;
    }
    
    void put(int key, int value) {
        pair<int,int> p = {key,value};
        for(int x = 0;x<hash.size();x++){
            if(hash[x].first == key){
                hash[x] = p;
                hash.push_back(hash[x]);
                hash.erase(hash.begin()+x);
                return;
            }
        }
        if(hash.size()>=capacity){
            hash.erase(hash.begin());
        }
        hash.push_back(p);
    }
};
