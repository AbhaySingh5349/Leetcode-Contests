Question Link: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

class Solution {
public:
    
    bool possible(int n, int k, vector<int>& qty){
        int m=qty.size();
        int c=0;
        for(int i=0;i<m;i++){
            c+=(qty[i]/k)+(qty[i]%k!=0);
        }
        return (c<=n);
    }
    
    int minimizedMaximum(int n, vector<int>& qty) {
        int m=qty.size();
        
        int maxe=*max_element(qty.begin(),qty.end());
        
        int r=maxe;
        int l=1;
        
        while(l<r){
            int m=l+(r-l)/2;
            if(possible(n,m,qty)){
                r=m;
            }else{
                l=m+1;
            }
        }
        return l;
    }
};
