Question Link: https://leetcode.com/problems/maximum-running-time-of-n-computers/

class Solution {
public:
    
    #define ll long long
    
    bool possible(int n, vector<int> &bat, ll int hrs){
        ll int s=0;
        for(int i=0;i<bat.size();i++){
            s += bat[i];
            if(s>=hrs){
                s-=hrs;
                n--;
            }
            if(n==0) return true;
        }
        return false;
    }
    
    long long maxRunTime(int n, vector<int> &bat) {
        ll int l=1, r=0;
        
        for(int i=0;i<bat.size();i++) r += bat[i];
        r/=n;
        
        sort(bat.begin(),bat.end());
        while(l<r){
            ll int m=l+(r-l+1)/2;
            
            if(possible(n,bat,m)){
                l=m;
            }else{
                r=m-1;
            }
        }
        return l;
    }
};
