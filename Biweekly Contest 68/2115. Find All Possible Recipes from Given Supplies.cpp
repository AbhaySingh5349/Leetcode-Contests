Question Link: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/

// Approach 1:

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


// Approach 2:

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipies, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        map<string,int> indegree; // to store the indegree of all recipes
        
        map<string,vector<string>> graph;
        
        for(int i=0;i<recipies.size();i++){
            string rec=recipies[i];
            
            for(int j=0;j<ingredients[i].size();j++){
                string ing=ingredients[i][j];
                
                graph[ing].push_back(rec);
                indegree[rec]++;
            }
        }
        
        queue<string> q;
        for(int i=0;i<supplies.size();i++) q.push(supplies[i]);
        
        vector<string> ans;
        while(q.size()>0){
            string sup=q.front();
            q.pop();
            
            for(auto rec : graph[sup]){
                indegree[rec]--;
                if(indegree[rec] == 0){
                    q.push(rec);
                    ans.push_back(rec);
                }
            }
        }
        return ans;
    }
};
