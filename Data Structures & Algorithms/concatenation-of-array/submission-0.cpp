class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> arr = nums;
        for(int x = 0; x<nums.size();x++){
            arr.push_back(nums[x]);
        }
        return arr;
    }
};