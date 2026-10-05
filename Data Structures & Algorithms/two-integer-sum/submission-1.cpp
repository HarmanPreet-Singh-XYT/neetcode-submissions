class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            int difference = target-nums[i];
            int required = target-difference;
            if(mp.find(required) != mp.end()){
                int idx = mp[required];
                return {idx,i};
            }
            mp[difference] = i;
        }
        return {};
    }
};
