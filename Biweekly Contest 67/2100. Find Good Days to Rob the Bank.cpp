Question Link: https://leetcode.com/problems/find-good-days-to-rob-the-bank/

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int> &a, int time) {
        int n=a.size();
        
        vector<int> left(n,0), right(n,0);
        
        for(int i=1;i<n;i++){
            if(a[i]<=a[i-1]){
                left[i]=1+left[i-1]; // count of elemnts from [0,i-1] >= a[i]
            }
        }
        
        for(int i=n-2;i>=0;i--){
            if(a[i]<=a[i+1]){
                right[i]=1+right[i+1]; // count of elemnts from [i+1,n-1] >= a[i]
            }
        }
        
        vector<int> ans;
        for(int i=time;i<n-time;i++){
            if(left[i]>=time && right[i]>=time) ans.push_back(i);
        }
        return ans;
    }
};
