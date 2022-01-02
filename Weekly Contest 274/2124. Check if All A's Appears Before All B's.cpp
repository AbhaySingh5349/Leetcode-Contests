Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

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
