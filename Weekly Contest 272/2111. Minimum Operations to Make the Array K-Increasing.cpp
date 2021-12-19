Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution {
public:
    
    int search(vector<int> &lis, int val){
        int idx=-1;
        
        int l=0, r=lis.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            
            if(lis[m]>val){
                idx=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return idx;
    }
    
    int lengthOfLIS(vector<int> &a) {
        int n=a.size();
        
        vector<int> lis;
        lis.push_back(a[0]);
        
        for(int i=1;i<n;i++){
            int pre=lis.back();
            
            if(a[i]>=pre){
                lis.push_back(a[i]);
            }else{
                int idx=search(lis,a[i]); // ceil idx element
                if(idx!=-1) lis[idx]=a[i];
            }
        }
        return lis.size();
    }
    
    int kIncreasing(vector<int> &a, int k) {
        int n=a.size();
        int ans=0;
        
        for(int i=0;i<k;i++){
            vector<int> v;
            for(int j=i;j<n;j+=k) v.push_back(a[j]);
            
            ans += (v.size()-lengthOfLIS(v));
        }
        
        return ans;
    }
};
