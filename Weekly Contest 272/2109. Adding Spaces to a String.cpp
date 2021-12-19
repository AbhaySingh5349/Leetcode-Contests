Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        sort(spaces.begin(),spaces.end());
        
        string ans="";
        int idx=0;
        for(int i=0;i<s.length();i++){
            if(idx<spaces.size() && spaces[idx]==i){
                ans+=' ';
                idx++;
            }
            ans+=s[i];
        }
        
        return ans;
    }
};
