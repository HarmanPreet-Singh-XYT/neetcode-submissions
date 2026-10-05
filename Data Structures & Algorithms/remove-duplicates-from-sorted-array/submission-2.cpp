class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> arr = nums;
        nums = {};
        nums.push_back(arr[0]);
        for(int x=1; x<arr.size();x++){
            if(nums.back() != arr[x]){
                nums.push_back(arr[x]);
            }
        }
        return nums.size();
    }
};