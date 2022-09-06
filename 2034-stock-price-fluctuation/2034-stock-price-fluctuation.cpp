class StockPrice {
public:
    // stack<int> minPrice;
    // stack<int> maxPrice;
    int maxTimeStamp = INT_MIN;
    unordered_map<int,int> timePriceMap;
    map<int,int> priceMap;
    StockPrice() {
        timePriceMap = {};
        priceMap = {};
    }
    
    void update(int timestamp, int price) {
        maxTimeStamp = max(maxTimeStamp,timestamp);
        if(timePriceMap.find(timestamp)!=timePriceMap.end()){
            int oldPrice = timePriceMap[timestamp];
            priceMap[oldPrice]--;
            if(priceMap[oldPrice]==0)
                priceMap.erase(oldPrice);
        }
        timePriceMap[timestamp]= price;
        priceMap[price]++;

        
    }
    
    int current() {
        return timePriceMap[maxTimeStamp];
    }
    
    int maximum() {
        return priceMap.rbegin()->first;
    }
    
    int minimum() {
        return priceMap.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */