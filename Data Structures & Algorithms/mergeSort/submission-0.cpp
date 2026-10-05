// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
    vector<Pair> merge(vector<Pair> pair1,vector<Pair> pair2){
        vector<Pair> temp;
        int i = 0;
        int j = 0;
        while(i<pair1.size() && j < pair2.size()){
            if(pair1[i].key > pair2[j].key){
                temp.push_back(pair2[j]);
                j++;
            }else{
                temp.push_back(pair1[i]);
                i++;
            }
        }
        while(i<pair1.size()){
            temp.push_back(pair1[i]);
            i++;
        }
        while(j<pair2.size()){
            temp.push_back(pair2[j]);
            j++;
        }
        return temp;
    }
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        if(pairs.size() < 2){
            return pairs;
        }
        int mid = pairs.size()/2;
        vector<Pair> left (pairs.begin(),pairs.begin()+mid);
        vector<Pair> right (pairs.begin()+mid,pairs.end());
        vector<Pair> leftArr = mergeSort(left);
        vector<Pair> rightArr = mergeSort(right);
        return merge(leftArr,rightArr);
    }
};
