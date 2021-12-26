Question Link: https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/

class Solution {
public:
    
    bool leftToRight(string s, string locked){
        int open=0, close=0, free=0;
        
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(locked[i]=='1'){
                if(ch=='('){
                    open++;
                }else{
                    close++;
                }
            }else{
                free++;
            }
            if(close>open+free) return false;
        }
        
        return true;
    }
    
    bool rightToLeft(string s, string locked){
        int open=0, close=0, free=0;
        
        for(int i=s.length()-1;i>=0;i--){
            char ch=s[i];
            if(locked[i]=='1'){
                if(ch=='('){
                    open++;
                }else{
                    close++;
                }
            }else{
                free++;
            }
            if(open>close+free) return false;
        }
        
        return true;
    }
    
    bool canBeValid(string s, string locked) {
        if(s.length()%2==1) return false;
        
        return (leftToRight(s,locked) && rightToLeft(s,locked));
    }
};
