// "cupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuc"

class Solution
{
    bool ok(string s)
    {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - 1 - i])
                return false;
        }
        return true;
    }

public:
    bool validPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            // cout << l << " " << r << endl;
            if (s[l] == s[r])
                l++, r--;
            else {
                // we must try BOTH...
                // o.w. WA on "lcuppucul" kind
                // if(s[l + 1] == s[r])
                //     l++, del = true;
                // else if(s[l] == s[r - 1])
                //     r--, del = true;
                // else
                //     return false;

                string try1 = s.substr(l + 1, r - l);
                string try2 = s.substr(l, r - l);
                return ok(try1) || ok(try2);
            }
        }

        return true;
    }
};