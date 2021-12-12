Question Link: https://leetcode.com/problems/watering-plants-ii/

class Solution {
public:
    int minimumRefill(vector<int>& a, int capacityA, int capacityB) {
        int n=a.size();
        
        int ca=capacityA, cb=capacityB;
        
        int ans=0;
        
        int i=0, j=n-1;
        while(i<j){
            if(ca>=a[i]){
                ca-=a[i];
            }else{
                ca=capacityA;
                ca-=a[i];
                
                ans++;
            }
            
            if(cb>=a[j]){
                cb-=a[j];
            }else{
                cb=capacityB;
                cb-=a[j];
                
                ans++;
            }
            
            i++, j--;
        }
        
        if(i==j && a[i] > max(ca,cb)) ans++;
        
        return ans;
    }
};
