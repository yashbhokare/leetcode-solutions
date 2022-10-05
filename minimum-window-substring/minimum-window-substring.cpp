class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> t_mapper;
        for(auto ch:t) t_mapper[ch]++;
        
        int min_size = INT_MAX;
        int min_index=-1;
        
        unordered_map<char,int> curr_mapper;
        int left=0;
        int right=0;
        int count = t_mapper.size();
        int n = s.size();
        while(right<n){
            char curr = s[right];
            if(t_mapper.find(curr)!=t_mapper.end()){
                curr_mapper[curr]++;
                if(curr_mapper[curr]==t_mapper[curr]){
                    count--;
                }
            }
            while(count==0){
                char temp = s[left];
                if(right-left+1<min_size){
                    min_size = right-left+1;
                    min_index = left;
                }
                if(t_mapper.find(temp)!=t_mapper.end()){
                    curr_mapper[temp]--;
                    if(curr_mapper[temp]<t_mapper[temp]){
                        count++;
                    }
                }

                left++;
            }
            
            right++;
        }
        if(min_index==-1) return "";
        // cout<<min_index<<endl;
        // cout<<min_size;
        return s.substr(min_index,min_size);
    }
};

// Time Complexity O(2S + T)