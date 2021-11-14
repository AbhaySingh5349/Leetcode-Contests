Question Link: https://leetcode.com/problems/most-beautiful-item-for-each-query/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size(), m=queries.size();
        
        map<int,int> mp;
        
        for(int i=0;i<n;i++){
            int p=items[i][0], b=items[i][1];
            if(mp.find(p)==mp.end()){
                mp[p]=b;
            }else{
                int prev=mp[p];
                mp[p]=max(prev,b);
            }
        }
        map<int,int> :: iterator it;
        int maxb=-1;
        for(it=mp.begin();it!=mp.end();it++){
            int p=it->first;
            int b=mp[p];
            maxb=max(maxb,b);
            mp[p]=maxb;
        }
        
        vector<int> ans(m,0);
        for(int i=0;i<m;i++){
            int p=queries[i];
            
            if(mp.find(p)!=mp.end()){
                ans[i]=mp[p];
            }else{
                auto it = mp.lower_bound(p);
                if(it!=mp.begin()){
                    --it;
                    ans[i]=it->second;
                }
            }
        }
        
        return ans;
    }
};
