// fast
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int l = 0;
        unordered_map<char, int> cnt, target;
        for (auto i : t)
            target[i]++;
        bool ok = false;
        int sz = 0;
        string ans;
        int al = -1, ar = s.length() + 1;
        for (int r = 0; r < s.length(); r++) {
            cnt[s[r]]++; // [l, r]
            // cout << "add " << s[r] << " " << cnt[s[r]] << endl;
            if (target.find(s[r]) != target.end() && target[s[r]] == cnt[s[r]])
                sz++;
            if (sz == target.size())
                ok = true;
            while (ok && l < r) {
                // cout << "rm " << l << " " << r << " " << s[l] << " " << cnt[s[l]] <<
                // endl;
                if (target.find(s[l]) == target.end())
                    cnt[s[l]]--, l++;
                else if (target[s[l]] <= cnt[s[l]] - 1)
                    cnt[s[l]]--, l++;
                else {
                    // cout << "out " << s[l] << " " << target[s[l]] << " " << cnt[s[l]]
                    // << endl;
                    break;
                }
            }

            // cout << "(l, r) = " << l << " " << r << " " << ok << endl;
            if (ok && (r - l + 1) < (ar - al + 1))
                al = l, ar = r;
        }

        // cout << al << " " << ar << endl;
        if (al == -1)
            return "";
        return s.substr(al, ar - al + 1);
    }
};

// slow
class Solution
{
private:
    bool check(map<char, int> &cnt, map<char, int> &target, bool &ok)
    {
        for (auto i : target) {
            if (cnt.find(i.first) == cnt.end())
                return false;
            if (cnt[i.first] < i.second)
                return false;
        }
        ok = true;
        return true;
    }

public:
    string minWindow(string s, string t)
    {
        int l = 0;
        map<char, int> cnt, target;
        for (auto i : t)
            target[i]++;
        bool ok = false;
        string ans;
        int al = -1, ar = s.length() + 1;
        for (int r = 0; r < s.length(); r++) {
            cnt[s[r]]++; // [l, r]
            while (check(cnt, target, ok) && l < r) {
                cnt[s[l]]--;
                if (check(cnt, target, ok))
                    l++;
                else {
                    cnt[s[l]]++;
                    break;
                }
            }

            // cout << "(l, r) = " << l << " " << r << " " << ok << endl;
            if (ok && (r - l + 1) < (ar - al + 1))
                al = l, ar = r;
        }

        // cout << al << " " << ar << endl;
        if (al == -1)
            return "";
        return s.substr(al, ar - al + 1);
    }
};