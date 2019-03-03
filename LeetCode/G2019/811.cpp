class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> cnt;
        
        for(auto i : cpdomains) {
            stringstream ss(i);
            int freq;
            string url;
            ss >> freq >> url;
            
            cnt[url] += freq;
            for(int j = 0; j <(int)url.length(); j++) {
                if(url[j] == '.') {
                    cnt[url.substr(j +1)] += freq;
                }
            }
        }
        
        vector<string>ans;
        for(auto i : cnt) {
            ans.push_back(to_string(i.second) + " " + i.first);
        }
        return ans;
    }
};
