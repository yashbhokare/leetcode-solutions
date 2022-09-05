class Logger {
public:
    unordered_map<string,int> mapper;
    int index=0;
    Logger() {
        mapper = {};
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        // cout<<
        index++;
        
        if(mapper.find(message)!=mapper.end()){
            // cout<<index<<". "<<message<<" "<<timestamp<<"   "<<mapper[message]<<endl;
            if(timestamp>=mapper[message]){
                mapper[message]=timestamp+10;
                // cout<<index<<". "<<message<<"\t"<<timestamp<<"\t"<<mapper[message]<<endl;
                return true;
            }else {
                // cout<<index<<". "<<message<<"\t"<<timestamp<<"\t"<<mapper[message]<<endl;
                return false;
            }
        }
        mapper[message]=timestamp+10;
        // cout<<index<<". "<<message<<"\t"<<timestamp<<"\t"<<mapper[message]<<endl;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */