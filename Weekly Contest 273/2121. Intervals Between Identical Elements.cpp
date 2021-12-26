Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution {
public:
    
    #define ll long long
    
    vector<long long> getDistances(vector<int>& a) {
        int n=a.size();
        
        vector<ll int> sub1(n,0), sub2(n,0);
        
        unordered_map<int,ll int> mp; // to store index of previous occurance of element
        unordered_map<int,ll int> dist; // summation of abs(i-j) for all occurance of element encounterd previously which can be used to update distance for next element
        unordered_map<int,ll int> count; // storing frequency of occurance of element
        
        
        for(int i=n-1;i>=0;i--){
            if(mp.find(a[i])==mp.end()){
                dist[a[i]]=0;
                count[a[i]]=0;
            }else{
                sub1[i]=count[a[i]]*abs(i-mp[a[i]])+dist[a[i]];
                dist[a[i]]=sub1[i];
            }
            mp[a[i]]=i;
            count[a[i]]++;
        }
        
        mp.clear(), dist.clear(), count.clear();
        for(int i=0;i<n;i++){
            if(mp.find(a[i])==mp.end()){
                dist[a[i]]=0;
                count[a[i]]=0;
            }else{
                sub2[i]+=count[a[i]]*abs(i-mp[a[i]])+dist[a[i]];
                dist[a[i]]=sub2[i];
            }
            count[a[i]]++;
            mp[a[i]]=i;
        }
        
        vector<ll> ans(n,0);
        for(int i=0;i<n;i++) ans[i]=sub1[i]+sub2[i];
        
        return ans;
    }
};
