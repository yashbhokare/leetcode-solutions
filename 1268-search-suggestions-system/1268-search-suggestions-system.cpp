class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        return suggestedProductsBinaryApproach(products,searchWord);
    }
    
    vector<vector<string>> suggestedProductsBinaryApproach(vector<string>& products, string searchWord){
        
        // Sort Products
        sort(products.begin(),products.end());
        
        //Array to store the result
        vector<vector<string>> result;
        
        int start = 0;
        int bsStart =0;
        int end = products.size();
        
        string prefix = "";
        //Iterate through each char in searchWord
        for(auto ch:searchWord){
            
            prefix+=ch;
            // Find the index of first element with prefix char
            start = lower_bound(products.begin()+bsStart,products.end(),prefix)-products.begin();
            
            vector<string> ans;
            // cout<<prefix<<" ";
            for(int i=start;i<min(start+3,end);i++){
                // Compare the product string with prefix if it matches then continue else break
                if(products[i].compare(0,prefix.length(),prefix)!=0) break;
                
                ans.push_back(products[i]);
                // cout<<products[i]<<" ";
            }
            // cout<<endl;
            result.push_back(ans);
            bsStart= start;
        }
        return result;
    }
};