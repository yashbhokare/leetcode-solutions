class Solution {
public:
    vector<vector<int>> transactions;
    int maxProfit(int k, vector<int>& prices) {
        unordered_map<int,pair<int,int>> mapper;
        int index=0;
        
        if(prices.size()<=0 || k<=0) return 0;

        
        int start=prices[0];
        int end = 0;
        for(int i=1;i<prices.size();i++){
                if(prices[i]<=start){
                    start = prices[i];
                }else {
                    transactions.push_back({start,prices[i]});
                    start = prices[i];
                }
        }
        // int start = 0;
        // int end = 0;
        // for (int i = 1; i < prices.size(); i++) {
        //     if (prices[i] >= prices[i - 1]) {
        //         end = i;
        //     } else {
        //         if (end > start) {
        //             transactions.push_back({prices[start],prices[end]});
        //         }
        //         start = i;
        //     }
        // }
        // if (end > start) {
        //     transactions.push_back({prices[start],prices[end]});
        // }
        
        // display();
        while(transactions.size()>k){
            
            int min_delete_loss = INT_MAX;
            int delete_index=0;
            for(int i=0;i<transactions.size();i++){
                int profit = transactions[i][1]-transactions[i][0];
                if(profit<min_delete_loss){
                    min_delete_loss = profit;
                    delete_index = i;
                }
            }
            
            int min_merge_loss = INT_MAX;
            int merge_index = 0;
            for(int i=1;i<transactions.size();i++){
                int profit_loss = transactions[i-1][1]-transactions[i][0];
                if(profit_loss<min_merge_loss){
                    min_merge_loss = profit_loss;
                    merge_index = i;
                }
            }
            
            if(min_delete_loss<=min_merge_loss){
                transactions.erase(transactions.begin()+delete_index);
            }else {
                // cout<<"Index:"<<merge_index<<" "<<min_merge_loss<<endl;
                transactions[merge_index-1][1] = transactions[merge_index][1];
                transactions.erase(transactions.begin()+merge_index);
            }
            // display();
        }
       
         int result = 0;
         for(auto t:transactions){
             result+=t[1]-t[0];
         }
        
        return result;
    }
    
    void display(){
        cout<<"************"<<endl;
          for(auto t:transactions){
            cout<<t[0]<<" "<<t[1]<<endl;
        }
    }
};