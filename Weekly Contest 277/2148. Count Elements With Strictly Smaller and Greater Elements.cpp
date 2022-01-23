Question Link: https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/

// Approach 1:

class Solution {
public:
    int countElements(vector<int> &a) {
        int n=a.size();
        
        int c=0;
        for(int i=0;i<n;i++){
            bool small=false, large=false;
            for(int j=0;j<n;j++){
                if(a[j]>a[i]) large=true;
                if(a[j]<a[i]) small=true;
            }
            if(small && large) c++;
        } 
        
        return c; 
    }
};

// Approach 2:

class Solution {
public:
    int countElements(vector<int> &a) {
        int n=a.size();
        
        int c=0;
        
        int mine=*min_element(a.begin(),a.end());
        int maxe=*max_element(a.begin(),a.end());
        
        for(int i=0;i<n;i++){
            if(a[i]>mine && a[i]<maxe) c++;
        }
        
        return c; 
    }
};
