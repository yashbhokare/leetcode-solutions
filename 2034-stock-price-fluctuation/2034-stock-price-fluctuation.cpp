class StockPrice {
public:
    // stack<int> minPrice;
    // stack<int> maxPrice;
    int currPrice;
    map<int,int> timeMap;
    map<int,int> priceMap;
    StockPrice() {
        timeMap = {};
        priceMap = {};
    }
    
    void update(int timestamp, int price) {
        if(timeMap.find(timestamp)!=timeMap.end()){
            int oldPrice = timeMap[timestamp];
            priceMap[oldPrice]--;
            if(priceMap[oldPrice]==0)
                priceMap.erase(oldPrice);
        }
        timeMap[timestamp]= price;
        priceMap[price]++;

        
    }
    
    int current() {
        return timeMap.rbegin()->second;
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