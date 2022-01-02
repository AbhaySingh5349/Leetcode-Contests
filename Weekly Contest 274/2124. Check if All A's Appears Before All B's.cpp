Question Link: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/

class Solution {
public:
    bool checkString(string s) {
        bool f1=false, f2=false;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'){
                if(f2==true) return false;
                f1=true;
            }else{
                f2=true;
            }
        }
        return true;
    }
};
