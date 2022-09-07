// class Solution {
// public:
   
//     vector<int> workDone;
//     unordered_map<int,int> mapper;
//     vector<int> amountPainted(vector<vector<int>>& paint) {
//         for(auto p:paint){
//             workDone.push_back(calAmountPainted(p[0],p[1]));
//         }
//         return workDone;
//     }
    
//     int calAmountPainted(int start, int end){
//         int work=0;
//         while(start<end){
//             // start not found
//             if(mapper.find(start)==mapper.end()){
//                 mapper[start]=end;
//                 work++;
//                 start++;
//             }else {
//                 int newStart = mapper[start];
//                 mapper[start] = max(mapper[start],end);
//                 start = newStart;
//             }
//         }
//         return work;
//     }


// };

class Solution {
public:
    
    int InsertInterval(map<int, int> &mp, int start, int end) 
    {
        auto up_it = mp.upper_bound(end);
        auto lo_it = std::prev(mp.lower_bound(start));
        
        lo_it = lo_it->second < start ? std::next(lo_it) : lo_it;              // First overlapping interval

        int paint = end - start;        
        for(auto it = lo_it; it != up_it; ++it) {
            paint -= std::min(end, it->second) - std::max(start, it->first);   // Substract overlapping interval from the paint
            
            start = std::min(start, it->first);                                // Update new interval to be stored in the map
            end   = std::max(end  , it->second);
        }
           
        mp.erase(lo_it, up_it);                                               // Remove overlapping intervals
        
        mp[start] = end;                                                      // Insert new interval
        return paint;
    }
    
    
    vector<int> amountPainted(vector<vector<int>>& paint) {
        map<int, int> mp;
        mp[INT_MIN] = INT_MIN;           // Insert dummy Interval
        mp[INT_MAX] = INT_MAX;
        
        vector<int> ans;
        for(auto p : paint) {
            ans.push_back(InsertInterval(mp, p[0], p[1]));
        }
        
        return ans;
    }
};