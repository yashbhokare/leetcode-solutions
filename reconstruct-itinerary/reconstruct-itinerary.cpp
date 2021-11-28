class Solution {
public:
    vector<string> result;
    map<string,multiset<string>> adjList;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &ticket:tickets){
            adjList[ticket[0]].insert(ticket[1]);
        }
//         stack<string> s;
//         s.push("JFK");
//         while(!s.empty()){
//             string val = s.top();
//             result.push_back(val);
//             s.pop();
            
//             auto it= adjList[val];
//             if(it.empty()){
//                 break;
//             }else {
//                 auto begin = it.begin();
//                 s.push(*begin);
//                 it.erase(begin);
//                 adjList[val] = it;
//             }
//         }
        recursion("JFK");
        return result;
    }
    
    void recursion(string s){
        while(!adjList[s].empty()){
            string next = *adjList[s].begin();
            adjList[s].erase(adjList[s].begin());
            recursion(next);
        }
        result.insert(result.begin(),s);
    }
};