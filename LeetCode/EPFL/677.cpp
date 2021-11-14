class MapSum {
private:
    // map<string, int> *data;
    map<string, int> data;
public:
    MapSum() {
        // this->data = new map<string, int>;
        this->data = map<string, int>();
    }
    
    void insert(string key, int val) {
        this->data[key] = val;
    }
    
    int sum(string prefix) {
        int ret = 0;
        for(auto tmp: data) {
            if(std::mismatch(prefix.begin(), prefix.end(), tmp.first.begin(), tmp.first.end()).first == prefix.end()) {
                ret += tmp.second;
            }
        }
        return ret;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
