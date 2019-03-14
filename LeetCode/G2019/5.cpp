class Solution
{
public:
    string longestPalindrome(string s)
    {
        // binary sesrch won't work
        int ans = 0;
        string str = "";
        for (int i = 0; i < s.length(); i++) {
            // this only work for odd length
            for (int j = 0; j < s.length(); j++) {
                int l = i - j;
                int r = i + j;

                if (l < 0 || r >= s.length())
                    break;

                if (s[l] == s[r]) {
                    if (r - l + 1 > ans) {
                        ans = r - l + 1;
                        str = s.substr(l, r - l + 1);
                    }
                } else {
                    break;
                }
            }

            // for even length
            int l = i, r = i + 1;
            if (r >= s.length())
                break;
            for (int j = 0; j < s.length(); j++) {
                if (l < 0 || r >= s.length())
                    break;

                if (s[l] == s[r]) {
                    if (r - l + 1 > ans) {
                        ans = r - l + 1;
                        str = s.substr(l, r - l + 1);
                    }
                } else {
                    break;
                }
                l--;
                r++;
            }
        }

        return str;
    }
};
