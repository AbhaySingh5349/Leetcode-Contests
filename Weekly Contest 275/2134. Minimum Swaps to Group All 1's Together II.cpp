Question Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

// --> let count of 1s be 'k', so after rearranging, we will be having a window of size 'k'

// Approach 1:

class Solution {
public:
    int minSwaps(vector<int> &a) {
        int n=a.size();
        
        int k=0, zero=0;
        for(int i=0;i<n;i++) k += (a[i]==1);
        
        a.insert(a.end(), a.begin(), a.end()); // doubling the size of array as it is circular
        
        int ans=n;
        
        int i=0, j=0, one=0;
        while(j<2*n){
            one += (a[j]==1);
            
            if(j-i+1 == k){
                ans = min(ans,k-one);
                one -= (a[i]==1);
                
                i++;
            }
            j++;
        }
        
        return (ans==n ? 0:ans);
    }
};

// Approach 2:

class Solution {
public:
    int minSwaps(vector<int> &a) {
        int n=a.size();
        
        int k=0, zero=0;
        for(int i=0;i<n;i++) k += (a[i]==1);
        
        int ans=n;
        
        int i=0, j=0, one=0;
        while(j<n+k){
            one += (a[j%n]==1);
            
            if(j-i+1 == k){
                ans = min(ans,k-one);
                one -= (a[i%n]==1);
                
                i++;
            }
            j++;
        }
        
        return (ans==n ? 0:ans);
    }
};
