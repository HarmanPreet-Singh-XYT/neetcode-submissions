class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int len = nums.size();
        for(int x = 0; x<len;x++){
            nums.push_back(nums[x]);
        }
        return nums;
    }
};