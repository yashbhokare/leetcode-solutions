class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n= quality.size();
        vector<pair<double,int>> wagePerQuality;
        for(int i=0;i<n;i++){
            double ratio = (double)wage[i]/quality[i];
            wagePerQuality.push_back({ratio,quality[i]});
        }
        sort(wagePerQuality.begin(),wagePerQuality.end());
        
       priority_queue<double,vector<double>> maxHeap;
        double total = 0;
        for(int workers=0;workers<k;workers++){
            maxHeap.push(wagePerQuality[workers].second);
            total+=wagePerQuality[workers].second;
        }
        
        double minResult = total*wagePerQuality[k-1].first;
        
        for(int captain=k;captain<n;captain++){
                int currQuality = wagePerQuality[captain].second;
                maxHeap.push(currQuality);
                double maxValue = maxHeap.top();
                maxHeap.pop();
                total-=maxValue;
                total+=currQuality;
                double currResult = total*wagePerQuality[captain].first;
                minResult = min(minResult,currResult);
        }
                
        return minResult; 
    }       
        
};

//https://www.youtube.com/watch?v=o8emK4ehhq0