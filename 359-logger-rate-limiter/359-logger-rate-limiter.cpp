class Logger {
public:
    unordered_map<string,int> mapper;
    Logger() {
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(mapper.find(message)!=mapper.end()){
            if(timestamp>=mapper[message]){
                mapper[message]=timestamp+10;
                return true;
            }else {
                return false;
            }
        }
        mapper[message]=timestamp+10;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */