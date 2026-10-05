class KthLargest {
    vector<int> arr;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        arr = nums;
    }
    
    int add(int val) {
        arr.push_back(val);
        sort(arr.begin(),arr.end());
        return arr[arr.size()-kth];
    }
};