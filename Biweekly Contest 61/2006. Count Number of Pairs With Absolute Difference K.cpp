class Solution {
public:
    int countKDifference(vector<int>& a, int k) {
        int n=a.size();
        int c=0;
    /*    for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int d=abs(a[i]-a[j]);
                if(d==k) c++;
            }
        } */
        
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int x=a[i]+k;
            if(mp.find(x)!=mp.end()) c+=mp[x];
            mp[a[i]]++;
        }
        mp.clear();
        for(int i=0;i<n;i++){
            int x=a[i]-k;
            if(mp.find(x)!=mp.end()) c+=mp[x];
            mp[a[i]]++;
        }
        
        return c; 
    }
};
