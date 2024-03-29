class Solution {
public:
    unordered_set<string> supply; // Add all supplies to set
    unordered_set<string> cannotCook; // Add recipes which cannot be made
    unordered_map<string,vector<string>> recMapper; // Add recipe map with ingredients
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        // Insert all supplies in set
        for(auto s:supplies) supply.insert(s);
        
        // Add recipe map with ingredients
        for(int i=0;i<recipes.size();i++) recMapper[recipes[i]] = ingredients[i];
       
        // Store the result
        vector<string> result;
        
        // Check if cycle exists
        unordered_set<string> visited;
        
        for(auto recipe:recipes){
            if(dfs(recipe,visited)) {
                result.push_back(recipe);
            }
        }
        return result;
    }
    
    
    
    bool dfs(string recipe,unordered_set<string>& visited){
      
        //Check if the recipie has already been tried
        if(cannotCook.find(recipe)!=cannotCook.end()) return false;
            
        // Check if recepie exists in supplies
        if(supply.find(recipe)!=supply.end()) return true;
        
        visited.insert(recipe);
        bool result=true;
        for(auto ingredient:recMapper[recipe]){
            // Check if ingredient exits inside supplies if yes then continue;
            if(supply.find(ingredient)!=supply.end()) continue;
            
            // Check if ingredient exits inside recepie and if it has not been visited if yes then dfs;
            if(recMapper.find(ingredient)!=recMapper.end() && visited.find(ingredient)==visited.end())
            {
                if(dfs(ingredient,visited)){
                // If the given recepie can be made just add it to supply
                   supply.insert(ingredient);
                }else {
                    cannotCook.insert(recipe);
                    result=false;
                    break;
                }
            }else {
                cannotCook.insert(ingredient);
                result=false;
                break;
            }
                
        }
        // Remove the recipe i.e for Back tracking
        visited.erase(recipe);
        
        // If recipe is possible to cook add to supply chain
        if(result) supply.insert(recipe);
        
        return result;
        
    }
};