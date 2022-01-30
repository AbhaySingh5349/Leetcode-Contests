Question Link: https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/

// Approach 1:

class Solution {
public:
    vector<int> maxScoreIndices(vector<int> &a) {
        int n=a.size();
        
        vector<int> left(n+1,0), right(n+1,0);
        
        for(int i=1;i<n+1;i++) left[i]=left[i-1]+(a[i-1]==0);
        for(int i=n-1;i>=0;i--) right[i]=right[i+1]+(a[i]==1);
        
        int maxs=0;
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int s=left[i]+right[i]; 
            if(s>maxs){
                maxs=s;
                ans={i};
            }else if(s==maxs){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
