class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int outerL = 0;
        int outerR = matrix.size()-1;
        while(outerL <= outerR){
            int outerM = (outerL+outerR)/2;
            if(matrix[outerM].back() >= target && matrix[outerM].front() <= target){
                int l = 0;
                int r = matrix[outerM].size()-1;
                while(l<=r){
                    int m = (l+r)/2;
                    if(matrix[outerM][m] < target){
                        l = m+1;
                    }else if(matrix[outerM][m] > target){
                        r = m-1;
                    }else{
                        return true;
                    }
                }
                return false;
            }else if(matrix[outerM].back() > target){
                outerR = outerM-1;
            }else{
                outerL = outerM+1;
            }
        }
        return false;
    }
};
