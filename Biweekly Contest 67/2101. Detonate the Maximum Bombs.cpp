Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution {
public:
    
    // DSU will fail as it is not necessary that both will affect each other, directed edge may also exist
    
    #define ll long long 
    
    bool isInside(ll int cx, ll int cy, ll int rad, ll int px, ll int py){
        // Compare radius of circle with distance of its center from given point
        if ((px-cx)*(px-cx) + (py-cy)*(py-cy) <= rad * rad ) return true;
        return false;    
    }
    
    int dfs(vector<int> graph[], int src, vector<bool> &visited){
        visited[src]=true;
        int c=1;
        for(int i=0;i<graph[src].size();i++){
            int child=graph[src][i];
            if(visited[child]==false) c+=dfs(graph,child,visited);
        }
        return c;
    }
    
    int maximumDetonation(vector<vector<int>> &a) {
        
        int n=a.size();
        vector<int> graph[n];
        
        for(int i=0;i<n;i++){
            int cx=a[i][0], cy=a[i][1], rad=a[i][2];
            
            for(int j=0;j<n;j++){
                if(i==j) continue;
                
                if(isInside(cx,cy,rad,a[j][0],a[j][1])) graph[i].push_back(j);
            } 
        }
        
        int ans=1;
        for(int i=0;i<n;i++){
            vector<bool> visited(n,false);
            int c=dfs(graph,i,visited);
            ans=max(ans,c);
        }
        
        return ans;
    }
};
