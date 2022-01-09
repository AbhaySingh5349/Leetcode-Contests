Question Link: https://leetcode.com/problems/capitalize-the-title/

class Solution {
public:
    
    string capitalizeTitle(string s) {
        int i=0, n=s.length();
        
        string ans="";
        while(i<n){
            int len=0;
            string sub="";
            while(i<n && isalpha(s[i])){
                sub += (s[i]>='A' && s[i]<='Z' ? s[i]-'A'+'a' : s[i]);
                i++;
            }
            
            if(sub.length()>2) sub[0] = sub[0]-'a'+'A';
            
            ans += sub + " ";
            
            i++;
        }
        return ans.substr(0,ans.length()-1);
    }
};
