Question Link: https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/

class Solution {
public:
    vector<int> findLonely(vector<int> &a) {
        int n=a.size();
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[a[i]]++;
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(mp[a[i]]>1) continue;
            if(mp.find(a[i]-1)==mp.end() && mp.find(a[i]+1)==mp.end()) ans.push_back(a[i]);
        }
        return ans;
    }
};
