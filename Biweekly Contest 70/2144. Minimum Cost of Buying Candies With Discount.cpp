Question Link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

class Solution {
public:
    int minimumCost(vector<int> &a) {
        int n=a.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++) pq.push(a[i]);
        
        int c=0;
        while(pq.size()>0){
            int f=pq.top();
            pq.pop();
            
            c+=f;
            
            if(pq.size()>0){
                int s=pq.top();
                pq.pop();
                
                c+=s;
            }
            if(pq.size()>0) pq.pop();
        }
        return c;
    }
};
