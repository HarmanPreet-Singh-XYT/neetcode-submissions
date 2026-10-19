class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 1;
        for(int x = 0; x<n-1;x++){
            int temp = one;
            one = one+two;
            two = temp;
        }
        return one;
    }
};
