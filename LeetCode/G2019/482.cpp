class Solution
{
public:
    string licenseKeyFormatting(string S, int K)
    {
        string clean;
        for (auto i : S)
            if (i != '-')
                clean += ('a' <= i && i <= 'z') ? i - 'a' + 'A' : i;

        reverse(clean.begin(), clean.end());

        string ans;
        for (int i = 0; i < (int)clean.size(); i++) {
            if (i != 0 && i % K == 0) {
                ans += "-";
            }
            ans += clean[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution
{
public:
    string licenseKeyFormatting(string S, int K)
    {
        vector<char> s;
        s.reserve(S.size());
        for (auto i : S)
            if (i != '-')
                s.push_back(('a' <= i && i <= 'z') ? i - 'a' + 'A' : i);

        string ans;
        int cnt = 0;
        while (s.size() > 0) {
            if (cnt > 0 && cnt % K == 0)
                ans += '-';
            ans += s.back();
            s.pop_back();
            cnt++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
