Question Link: https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/

class Solution {
public:
    
    vector<int> getFrequency(string s){
        vector<int> count(26,0);
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
        }
        return count;
    }
    
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> f1=getFrequency(word1);
        vector<int> f2=getFrequency(word2);
        
        for(int i=0;i<26;i++) if(abs(f1[i]-f2[i])>3) return false;
        
        return true;
    }
};
