class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2!=0) return {};
        vector<long long> result;
        long long total = 0;
        long long start = 2;
        while(total<finalSum){
            result.push_back(start);
            total+=start;
            start+=2;
        }
        if(total==finalSum) return result;
        long long diff = total-finalSum;
        long long index = (diff/2)-1;
        result.erase(result.begin()+index);
        return result;
    }
};