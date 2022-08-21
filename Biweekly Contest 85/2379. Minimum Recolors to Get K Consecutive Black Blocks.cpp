Question Link: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n=s.length();
        
        int bad=0; // count of 'W' in string of size 'k'
        int i=0, j=0;
        int ans=n;
        while(j<n){
            if(s[j]=='W') bad++;
            
            if(j-i+1 == k){
                ans=min(ans,bad);
                if(s[i]=='W') bad--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
