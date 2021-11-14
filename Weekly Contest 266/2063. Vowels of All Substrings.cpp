Question Link: https://leetcode.com/problems/vowels-of-all-substrings/

class Solution {
public:
    
    // Number of substrings that contain the i'th index is (i+1)*(n-i)
    
    #define ll long long
    
    long long countVowels(string s) {
        ll int n = s.length();
        
        ll int sum = 0;
        for (ll int i = 0; i < n; i++){
            // Check if ith character is a vowel
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                sum += (i+1)*(n-i); 
            }
        }
       
        return sum;
    }
};
