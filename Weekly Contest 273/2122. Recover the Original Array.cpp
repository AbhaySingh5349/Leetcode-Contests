Question Link: https://leetcode.com/problems/recover-the-original-array/

class Solution {
public:
    
    bool possible(multiset<int> st, int k, vector<int> &ans){
        while(st.size()>0){
            int low=*st.begin();
            int high=low+2*k;
            
            if(st.find(high)==st.end()) return false;
            
            ans.push_back((low+high)/2);
            
            // erase iterators and not elements as there might be multiple occurances of element
            st.erase(st.begin());
            auto it=st.find(high);
            st.erase(it);
        }
        return true;
    }
    
    vector<int> recoverArray(vector<int> &a) {
        sort(a.begin(),a.end()); 
        
        multiset<int> st(a.begin(),a.end());
        
        int low=a[0];
        for(int i=1;i<a.size();i++){
            vector<int> ans;
            
            int high=a[i];
            if((high-low)%2==0){
                int k=(high-low)/2;
                if(k>0 && possible(st,k,ans)) return ans;
            }
        }
        return {};
    }
};
