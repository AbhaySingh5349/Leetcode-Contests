Question Link: https://leetcode.com/problems/solving-questions-with-brainpower/

class Solution {
public:
    
    #define ll long long
    
    long long mostPoints(vector<vector<int>> &a) {
        int n=a.size();
        
        ll int dp[n];
        dp[n-1]=a[n-1][0];
        
        ll int ans=dp[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i]=max(dp[i+1],a[i][0]+(i+a[i][1]+1 < n ? dp[i+a[i][1]+1]:0));
            if(dp[i]>ans) ans=dp[i];
        }
        
        return ans;
    }
};
