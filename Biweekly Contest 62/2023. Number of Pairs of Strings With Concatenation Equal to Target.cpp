Question Link: https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/

class Solution {
public:
    int numOfPairs(vector<string>& a, string target) {
        int n=a.size();
        int c=0;
    /*    for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                string s=a[i]+a[j];
                if(s==target) c++;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                string s=a[i]+a[j];
                if(s==target) c++;
            }
        }
        return c; */
        
        int m=target.length();
        
        map<string,int> mp;
        for(int i=0;i<n;i++){
            string s=a[i];
            int len=s.length();
            if(len>m) continue;
            
            // pre + s = target
            string pre=target.substr(0,m-len);
            if(mp.find(pre)!=mp.end() && (pre+s==target)) c+=mp[pre];
            
            // s + pre = target
            string suf=target.substr(len);
            if(mp.find(suf)!=mp.end() && (s+suf==target)) c+=mp[suf];
            
            mp[s]++;
        }
        
        return c;
    }
};
