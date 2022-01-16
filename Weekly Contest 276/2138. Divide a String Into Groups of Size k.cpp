Question Link: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int i=0;
        int n=s.length();
        
        while(i<n){
            int x=k;
            string sub="";
            while(i<n && x--){
                sub+=s[i];
                i++;
            }
            while(sub.length()<k) sub += fill;
            ans.push_back(sub);
        }
        
        return ans;
        
    }
};
