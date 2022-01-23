Question Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/

// Approach 1:

class Solution {
public:
    
    vector<int> rearrangeArray(vector<int> &a) {
        int n=a.size();
        
        vector<int> pos,neg;
        for(int i=0;i<n;i++){
            if(a[i]>0) pos.push_back(a[i]);
            if(a[i]<0) neg.push_back(a[i]);
        }
        
        vector<int> ans;
        int i=0, j=0, n1=pos.size(), n2=neg.size();
        while(i<n1 && j<n2){
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        }
        while(i<n1) ans.push_back(pos[i++]);
        while(j<n2) ans.push_back(neg[j++]);
        
        return ans;
    }
};

// Approach 2:

class Solution {
public:
    
    vector<int> rearrangeArray(vector<int> &a) {
        int n=a.size();
        
        vector<int> ans(n);
        int pos=0, neg=1;
        for(int i=0;i<n;i++){
            if(a[i]>0){
                ans[pos]=a[i];
                pos += 2;
            }
            if(a[i]<0){
                ans[neg]=a[i];
                neg += 2;
            }
        }
        return ans;
    }
};
