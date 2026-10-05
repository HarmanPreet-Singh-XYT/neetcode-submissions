class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int each:nums){
            if(hash.find(each) != hash.end()){
                return true;
            }
            hash[each] = 1;
        }
        return false;
    }
};