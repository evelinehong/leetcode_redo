class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mymap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = mymap[key].upper_bound(timestamp);
        if (it == mymap[key].begin()) return "";
        else return prev(it)->second;
    }
    unordered_map <string, map<int, string>> mymap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */