Question Link: https://leetcode.com/problems/license-key-formatting/

class Solution {
public:
    
    struct node{
        int dist;
        int cost;
        int r;
        int c;
    };
    struct compare{
        bool operator()(const node &a, const node &b){
            if(a.dist != b.dist){
                return a.dist < b.dist;
            }else if(a.cost != b.cost){
                return a.cost < b.cost;
            }else if(a.r != b.r){
                return a.r < b.r;
            }
            return a.c < b.c;
        }
    };
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &price, vector<int> &start, int k) {
        int n=grid.size(), m=grid[0].size();
        
        int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        int len=0;
        
        set<pair<int,int>> visited;
        visited.insert({start[0],start[1]});
        
        int lb=price[0], ub=price[1];
        
        priority_queue<node,vector<node>,compare> pq;
        
        while(q.size()>0){
            int size=q.size();
            while(size--){
                pair<int,int> p=q.front();
                q.pop();
                
                int i=p.first, j=p.second;
                if(grid[i][j]!=1){
                    int curCost=grid[i][j];
                    if(curCost>=lb && curCost<=ub){
                        if(pq.size()<k){
                            pq.push({len,curCost,i,j});
                        }else if(pq.size()==k){
                            struct node tp=pq.top();
                            if(tp.dist > len){
                                pq.pop();
                                pq.push({len,curCost,i,j});
                            }else if(tp.dist==len){
                                if(tp.cost > curCost){
                                    pq.pop();
                                    pq.push({len,curCost,i,j});
                                }else if(tp.cost==curCost){
                                    if(tp.r > i){
                                        pq.pop();
                                        pq.push({len,curCost,i,j});
                                    }else if(tp.r==i && tp.c > j){
                                        pq.pop();
                                        pq.push({len,curCost,i,j});
                                    }
                                }
                            }
                        }
                    }
                }
                
                for(int k=0;k<4;k++){
                    int x=i+dxy[k][0], y=j+dxy[k][1];
                    if(x>=0 && y>=0 && x<n && y<m && visited.find({x,y})==visited.end() && grid[x][y]!=0){
                        visited.insert({x,y});
                        q.push({x,y});
                    }
                }
            }
            len++;
        }
        vector<vector<int>> ans;
        while(pq.size()>0){
            struct node cur=pq.top();
            pq.pop();
            
            ans.push_back({cur.r,cur.c});
            k--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
