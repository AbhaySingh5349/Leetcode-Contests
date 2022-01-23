Question Link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

// Approach 1:

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

// Approach 2:

class Solution {
public:
    int minimumCost(vector<int> &a) {
        int n=a.size();
        
        if(n==1) return a[0];
        if(n==2) return (a[0]+a[1]);
        
        sort(a.begin(),a.end());
        
        int c=0;
        for(int i=n-1;i>=0;i-=3) c += a[i] + (i>0 ? a[i-1]:0);
        
        return c;
    }
};
