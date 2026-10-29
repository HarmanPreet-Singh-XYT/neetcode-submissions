class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> temp = nums;
        for(int x = 0; x<nums.size();x++){
            temp.push_back(nums[x]);
        }
        return temp;
    }
};