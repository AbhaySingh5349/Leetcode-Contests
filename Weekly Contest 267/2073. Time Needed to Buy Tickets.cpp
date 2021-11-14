Question Link: https://leetcode.com/problems/time-needed-to-buy-tickets/

// Approach 1:

class Solution {
public:
    int timeRequiredToBuy(vector<int> &tickets, int k) {
        int t=0;
        
        queue<pair<int,int>> q;
        for(int i=0;i<tickets.size();i++) q.push({tickets[i],i});
        
        while(q.size()>0){
            int size=q.size();
            while(size--){
                int tick=q.front().first;
                int idx=q.front().second;
                q.pop();
                
                t++;
                
                tick--;
                if(tick==0){
                    if(idx==k) return t;
                }else{
                    q.push({tick,idx});
                }
            }
        }
        return -1; 
    }
};

// Approach 2:

class Solution {
public:
    int timeRequiredToBuy(vector<int> &tickets, int k) {
        int t=0;
        
        for(int i=0;i<tickets.size();i++) t+=min(tickets[i],tickets[k]-(i>k)); // people behind k will take 1 less ticket wrt k
        
        return t;
    }
};
