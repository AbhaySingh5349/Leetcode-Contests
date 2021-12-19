Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution {
public:
    long long getDescentPeriods(vector<int>& a) {
        int n=a.size();
        
        long long int dp[n], ans=1;
        dp[0]=1;
        
        for(int i=1;i<n;i++){
            dp[i]=1; // consdering sub-array formed by individual element
            if(a[i]+1==a[i-1]) dp[i]+=dp[i-1]; // new sub-arrays when current element combines with previous sub-arrays
            
            ans+=dp[i];
        }
        return ans;
    }
};
