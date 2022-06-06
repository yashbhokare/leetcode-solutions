class Solution {
public:
    static int comparator(pair<int,string> a, pair<int,string> b){
        if(a.first==b.first) return a.second < b.second;
        return a.first > b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mapper;
        vector<string> res;
        vector<pair<int,string>> wordList;
        int index=0;
        for(auto& word:words){
            auto it=mapper.find(word);
            if(it==mapper.end()){
                mapper[word]=index;
                wordList.push_back({1,word});
                index++;
            }else {
                int wordListIndex=mapper[word];
                wordList[wordListIndex].first++;
            }
        }
        // for(int i=0;i<wordList.size();i++){
        //     cout<<wordList[i].first<<"->"<<wordList[i].second<<endl;
        // }
        sort(wordList.begin(),wordList.end(),comparator);
        for(int i=0;i<k;i++){
            res.push_back(wordList[i].second);
        }
        return res;
    }
};