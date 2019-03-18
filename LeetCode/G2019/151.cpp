class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> ans;
        int n = s.length();
        for (int i = 0; i < n;) {
            while (i < n && s[i] == ' ')
                i++;
            if (i >= n)
                break;

            int idx = i;
            while (idx < n && s[idx] != ' ') {
                idx++;
            }
            ans.push_back(s.substr(i, idx - i));
            // cout << i << " " << idx << " :" << s.substr(i, idx - i) << endl;
            i = idx;
        }
        reverse(ans.begin(), ans.end());
        string ret;
        for (int i = 0; i < ans.size(); i++) {
            // cout << i << " " << ans[i] << endl;
            if (i != 0)
                ret += " ";
            ret += ans[i];
        }
        return ret;
    }
};
