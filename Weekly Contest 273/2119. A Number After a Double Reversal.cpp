Question Link: https://leetcode.com/problems/a-number-after-a-double-reversal/

class Solution {
public:
    
    int reverse(int n){
        int val=0;
        while(n>0){
            val = val*10+n%10;
            n/=10;
        }
        return val;
    }
    
    bool isSameAfterReversals(int num) {
        int val=reverse(reverse(num));
        
        return (val==num);
    }
};
