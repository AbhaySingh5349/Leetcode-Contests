Question Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipies, vector<vector<string>>& ing, vector<string>& supplies) {
        set<string> sup;
        for(int i=0;i<supplies.size();i++) sup.insert(supplies[i]);
        
        vector<string> ans;
        
        while(1){
            bool possible=false;
            for(int i=0;i<recipies.size();i++){
                if(sup.find(recipies[i])!=sup.end()) continue;
                
                bool canAdd=true;
                for(int j=0;j<ing[i].size();j++){
                    if(sup.find(ing[i][j])==sup.end()){
                        canAdd=false;
                        break;
                    }
                }
                
                if(canAdd){
                    possible=true;
                    sup.insert(recipies[i]);
                    ans.push_back(recipies[i]);
                }
            }
            if(possible==false) break;
        }
        return ans;
    }
};
