class TimeMap {
private:
unordered_map<string, vector<pair<string, int>>> store;


public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        pair<string, int> newPair= {value, timestamp};
        store[key].push_back(newPair);
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>> &vals= store[key];
        int left= 0;
        int right= vals.size()-1;
        int mid;
        string res;

        while(right>=left){
            mid= (right+left)/2;
            if(vals[mid].second==timestamp){
                return vals[mid].first;
            }

            if(vals[mid].second<=timestamp){
                left= mid+1;
                res= vals[mid].first;
            }
            else{
                right= mid-1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */