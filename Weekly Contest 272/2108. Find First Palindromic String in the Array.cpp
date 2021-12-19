Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution {
public:
    
    bool palin(string s){
        int i=0, j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++, j--;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& a) {
        int n=a.size();
        for(int i=0;i<n;i++){
            if(palin(a[i])) return a[i];
        }
        return "";
    }
};
