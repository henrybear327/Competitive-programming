class Solution
{
public:
    string countAndSay(int n)
    {
        string ans = "1";

        for (int i = 1; i < n; i++) {
            string tmp;
            char which = '\0';
            int cnt = 0;
            for (auto j : ans) {
                if (which == '\0') {
                    which = j;
                    cnt = 1;
                } else {
                    if (j == which) {
                        cnt++;
                    } else {
                        tmp += to_string(cnt) + which;
                        which = j;
                        cnt = 1;
                    }
                }
            }

            tmp +=
                to_string(cnt) + which; // don't forget to think about the last one!
            ans = tmp;
        }

        return ans;
    }
};
