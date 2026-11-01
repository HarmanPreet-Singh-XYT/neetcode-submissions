class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> output;
        for(const int each: nums1){
            bool found = false;
            for(int x = 0; x<nums2.size()-1;x++){
                if(each == nums2[x]){
                    for(int i = x+1; i<nums2.size();i++){
                        if(nums2[i] > each){
                            output.push_back(nums2[i]);
                            found = true;
                            break;
                        }
                    }
                    break;
                }
            }
            if(!found) output.push_back(-1);
        }
        return output;
    }
};