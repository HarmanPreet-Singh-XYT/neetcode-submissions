// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
    vector<Pair> quickSort(vector<Pair>& arr,int s, int e){
        if(e-s+1 < 2){
            return arr;
        }
        int pointer = s;
        int pivot = e;
        for(int i = s;i<pivot;i++){
            if(arr[i].key < arr[pivot].key){
                swap(arr[i],arr[pointer]);
                pointer++;
            }
        }
        swap(arr[pivot],arr[pointer]);
        quickSort(arr,s,pointer-1);
        quickSort(arr,pointer+1,e);
        return arr;
    }
public:
    vector<Pair> quickSort(vector<Pair>& pairs) {
        quickSort(pairs,0,pairs.size()-1);
        return pairs;
    }
};
