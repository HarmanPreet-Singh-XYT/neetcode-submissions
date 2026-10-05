class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> arr = nums;
        nums = {};
        for(int x =0; x<arr.size();x++){
            bool exists = false;
            for(int y =0; y<nums.size();y++){
                if(arr[x] == nums[y]){
                    exists = true;
                    break;
                }
            }
            if(!exists){
                nums.push_back(arr[x]);
            }
        }
        return nums.size();
    }
};