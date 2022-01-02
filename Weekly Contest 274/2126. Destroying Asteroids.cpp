Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int> &a) {
        int n=a.size();
        
        sort(a.begin(),a.end());
        
        long long int m=(long) mass;
        for(int i=0;i<n;i++){
            if(m >= a[i]){
                m += a[i];
            }else{
                return false;
            }
        }
        return true;
    }
};
