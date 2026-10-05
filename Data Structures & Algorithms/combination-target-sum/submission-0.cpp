class Solution {
    void dfs(const vector<int>& nums, int index, int target, vector<int> subset,vector<vector<int>>& result){
        if(target == 0){
            result.push_back(subset);
            return;
        }
        if(target<0 || index >=nums.size()){
            return;
        }
        subset.push_back(nums[index]);
        dfs(nums,index,target-nums[index],subset,result);
        subset.pop_back();
        dfs(nums,index+1,target,subset,result);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> subset;
        dfs(nums,0,target,subset,result);
        return result;
    }
};
