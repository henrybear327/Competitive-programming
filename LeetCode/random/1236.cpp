/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution
{
private:
    string getHostname(const string url)
    {
        string trimmed = url.substr(7, url.length());
        for (int i = 0; i < trimmed.size(); i++) {
            if (trimmed[i] == ':' || trimmed[i] == '/') {
                return trimmed.substr(0, i);
            }
        }

        return trimmed;
    }

public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser)
    {
        queue<string> q;
        set<string> result;
        string hostname = getHostname(startUrl);

        q.push(startUrl);
        result.insert(startUrl);
        while (q.size() > 0) {
            string cur = q.front();
            auto next = htmlParser.getUrls(cur);
            q.pop();

            for (auto &i : next) {
                if (hostname == getHostname(i) && result.find(i) == result.end()) {
                    result.insert(i);
                    q.push(i);
                }
            }
        }

        vector<string> ret;
        for (auto &i : result)
            ret.push_back(i);
        return ret;
    }
};
