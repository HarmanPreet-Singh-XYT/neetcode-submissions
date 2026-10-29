class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int s = nums.size();
        for(int x = 0; x<s;x++){
            nums.push_back(nums[x]);
        }
        return nums;
    }
};