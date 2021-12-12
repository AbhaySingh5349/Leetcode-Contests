Question Link: https://leetcode.com/problems/rings-and-rods/

class Solution {
public:
    int countPoints(string s) {
        int n=s.length();
        
        map<int,int> mp;
        for(int i=0;i<=9;i++) mp[i]=0;
        
        for(int i=1;i<n;i+=2){
            char col=s[i-1], rod=s[i]-'0';
            
            if(col=='R'){
                mp[rod] |= (1<<0);
            }else if(col=='G'){
                mp[rod] |= (1<<1);
            }else if(col=='B'){
                mp[rod] |= (1<<2);
            }
        }
        
        int c=0;
        for(int i=0;i<=9;i++) c+=(mp[i]==7);
        
        return c;
    }
};
