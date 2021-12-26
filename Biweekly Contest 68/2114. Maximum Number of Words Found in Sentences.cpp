Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution {
public:
    int mostWordsFound(vector<string>& v) {
        int ans=0;
        for(int i=0;i<v.size();i++){
            string s=v[i];
            int c=0;
            int j=0;
            while(j<s.length()){
                while(j<s.length() && isalpha(s[j])) j++;
                c++;
                j++;
            }
            ans=max(ans,c);
        }
        return ans;
    }
};
