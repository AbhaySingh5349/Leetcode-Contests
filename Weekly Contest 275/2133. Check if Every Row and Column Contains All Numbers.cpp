Question Link: https://leetcode.com/problems/capitalize-the-title/

class Solution {
public:
    bool checkValid(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n;i++){
            set<int> st;
            for(int j=0;j<n;j++) st.insert(grid[i][j]);
            
            for(int j=1;j<=n;j++) if(st.find(j)==st.end()) return false;
        }
        
        for(int j=0;j<n;j++){
            set<int> st;
            for(int i=0;i<n;i++) st.insert(grid[i][j]);
            
            for(int i=1;i<=n;i++) if(st.find(i)==st.end()) return false;
        }
        
        return true;
    }
};
