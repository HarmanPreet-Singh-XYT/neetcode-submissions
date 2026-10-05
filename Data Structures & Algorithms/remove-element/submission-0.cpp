class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      vector<int> temp = nums;
      nums = {};
      for(int x = 0; x<temp.size();x++){
        if(temp[x] != val) nums.push_back(temp[x]);
      }
      return nums.size();
    }
};