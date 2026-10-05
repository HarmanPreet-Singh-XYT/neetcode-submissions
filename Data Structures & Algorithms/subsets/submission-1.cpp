class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        for(int num:nums){
            int size = result.size();
            for(int x = 0;x<size;x++){
                vector<int> subset = result[x];
                subset.push_back(num);
                result.push_back(subset);
            }
        }
        return result;
    }
};
