Question Link: https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/

class Solution {
public:
    
    int count(int n, int i, int j, string &s, int idx){
        if(i<0 || j<0 || i==n || j==n) return -1;
        if(idx==s.length()) return 0;
        
        char dir=s[idx];
        
        int c=1;
        if(dir=='L'){
            c+=count(n,i,j-1,s,idx+1);
        }else if(dir=='R'){
            c+=count(n,i,j+1,s,idx+1);
        }else if(dir=='U'){
            c+=count(n,i-1,j,s,idx+1);
        }else if(dir=='D'){
            c+=count(n,i+1,j,s,idx+1);
        }
        return c;
    }
    
    vector<int> executeInstructions(int n, vector<int>& start, string s) {
        int m=s.length();
        vector<int> ans(m,0);
        
        for(int i=0;i<m;i++){
            ans[i]=count(n,start[0],start[1],s,i);
        }
        return ans;
    }
};
