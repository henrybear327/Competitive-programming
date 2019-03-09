class Solution
{
private:
    bool check(int mid, vector<string> &strs)
    {
        string cmp = strs[0].substr(0, mid);
        for (auto &i : strs) {
            string pre = i.substr(0, mid);
            if (cmp != pre)
                return false;
        }
        return true;
    }

public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";

        int mn = INT_MAX;
        for (auto &i : strs)
            mn = min(mn, (int)i.length());

        int l = 0, r = mn + 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (check(mid, strs))
                l = mid;
            else
                r = mid;
        }

        return strs[0].substr(0, l);
    }
};
