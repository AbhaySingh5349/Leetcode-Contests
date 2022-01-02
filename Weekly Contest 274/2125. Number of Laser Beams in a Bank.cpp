Question Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

class Solution {
public:
    int numberOfBeams(vector<string> &grid) {
        int n=grid.size(), m=grid[0].size();
        
        vector<int> v;
        
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<m;j++){
                c += (grid[i][j]=='1');
            }
            if(c!=0) v.push_back(c);
        }
        
        int c=0;
        for(int i=1;i<v.size();i++) c += (v[i]*v[i-1]);
        
        return c;
    }
};
