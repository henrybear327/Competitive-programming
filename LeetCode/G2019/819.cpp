class Solution
{
private:
    void lowercase(string &input)
    {
        for (auto &i : input)
            if ('A' <= i && i <= 'Z')
                i = i - 'A' + 'a';
    }

public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        unordered_set<string> ban;
        for (auto &i : banned)
            ban.insert(i);
        unordered_map<string, int> cnt;
        int mx = 0;
        lowercase(paragraph);
        for (int i = 0; i < paragraph.length();) {
            if (!('a' <= paragraph[i] && paragraph[i] <= 'z')) {
                i++;
                continue;
            }

            int j = i;
            while (j < paragraph.length() &&
                   ('a' <= paragraph[j] && paragraph[j] <= 'z'))
                j++;

            string token = paragraph.substr(i, j - i);
            // cout << i << " " << j << " " << token << endl;
            if (ban.find(token) == ban.end())
                cnt[token]++, mx = max(mx, cnt[token]);
            i = j;
        }

        for (auto i : cnt)
            if (i.second == mx)
                return i.first;
        return "";
    }
};
