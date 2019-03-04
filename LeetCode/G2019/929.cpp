static int desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}
();

class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> s;
        for (auto i : emails) {
            int at = i.find("@");
            string username = i.substr(0, at);
            string domain = i.substr(at + 1);

            int plus = username.find("+");
            if (plus != string::npos) {
                username = username.substr(0, plus);
            }

            string newUsername;
            for (auto j : username)
                if (j != '.')
                    newUsername += j;
            s.insert(newUsername + "@" + domain);
        }
        return s.size();
    }
};
