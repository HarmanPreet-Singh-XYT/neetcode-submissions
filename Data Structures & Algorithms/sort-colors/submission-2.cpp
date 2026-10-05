class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[] = {0,0,0};
        for(int x:nums){
            count[x] += 1;
        }
        int i = 0;
        for(int x =0;x<3;x++){
            for(int y = 0;y<count[x];y++){
                nums[i] = x;
                i++;
            }
        }
    }
};