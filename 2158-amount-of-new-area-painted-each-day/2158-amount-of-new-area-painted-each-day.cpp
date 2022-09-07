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
//                 start = mapper[start];
//             }
//         }
//         return work;
//     }


// };

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        // Lets create a map that stores where we started and where we ended
        vector<int> res;
        unordered_map<int, int> m;
        
        for(int i = 0; i < paint.size(); ++i)
        {
            int work = 0;
            int start = paint[i][0];
            int end = paint[i][1];
            
            while(start < end)
            {
                if(m.count(start))
                {
                    int prev_end = m[start];
                    m[start] = max(m[start], end);
                    start = prev_end;
                }
            
                else
                {
                    m[start] = end;
                    start += 1;
                    work += 1;
                }
            }
            res.push_back(work);
        }
        return res;
    }
};