Question Link: https://leetcode.com/problems/sum-of-subarray-ranges/

class Solution {
public:
    
    #define ll long long
    
    vector<int> greater(vector<int> v){ // storing index of nearest greater on right to current element
        int n=v.size();
        vector<int> ngr(n+1,n);
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && v[i]>=st.top().first) st.pop();
            if(st.size()>0) ngr[i]=st.top().second;
            st.push({v[i],i});
        }
        return ngr;
    }
    
    vector<int> smaller(vector<int> v){ // storing index of nearest smaller on right to current element
        int n=v.size();
        vector<int> nsr(n+1,n);
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && st.top().first>=v[i]) st.pop();
            if(st.size()>0) nsr[i]=st.top().second;
            st.push({v[i],i});
        }
        return nsr;
    }
    
    long long subArrayRanges(vector<int> &a) {
        int n=a.size();
        
        vector<int> ngr=greater(a);
        vector<int> nsr=smaller(a);
        
        ll int ans=0;
        
        for(int len=2;len<=n;len++){ // considering all sub-arrays of lengthy len
            vector<int> maxe, mine;
            int x=0, y=0;
                
            while(x<=n-len){
                y=max(x,y);
                while(ngr[y]<x+len) y=ngr[y]; // getting index of max element present in current sub-array
                
                maxe.push_back(a[y]);
                x++;
            }
                
            x=0, y=0;
            while(x<=n-len){
                y=max(x,y);
                while(nsr[y]<x+len) y=nsr[y]; // getting index of min element present in current sub-array
                
                mine.push_back(a[y]);
                x++;
            }
            
            for(int i=0;i<min(mine.size(),maxe.size());i++) ans += (maxe[i]-mine[i]);
        }
        return ans;
    }
};
