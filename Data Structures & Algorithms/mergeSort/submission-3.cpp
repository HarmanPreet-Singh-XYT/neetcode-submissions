// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
    void mergeSortHelper(vector<Pair>& pairs,int s,int e){
        if(e-s+1 < 2){
            return;
        }
        int m = (s+e)/2;
        mergeSortHelper(pairs,s,m);
        mergeSortHelper(pairs,m+1,e);
        merge(pairs,s,m,e);
    }
    void merge(vector<Pair>& pairs, int s, int m, int e){
        vector<Pair> L(pairs.begin()+s,pairs.begin()+m+1);
        vector<Pair> R(pairs.begin()+m+1,pairs.begin()+e+1);
        int i = 0;
        int j = 0;
        int k = s;
        while(i<L.size() && j<R.size()){
            if(L[i].key <= R[j].key){
                pairs[k] = L[i];
                i++;
            }else{
                pairs[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < L.size()) {
            pairs[k] = L[i];
            ++i;
            ++k;
        }
        while (j < R.size()) {
            pairs[k] = R[j];
            ++j;
            ++k;
        }
    }
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        mergeSortHelper(pairs,0,pairs.size()-1);
        return pairs;
    }
};
