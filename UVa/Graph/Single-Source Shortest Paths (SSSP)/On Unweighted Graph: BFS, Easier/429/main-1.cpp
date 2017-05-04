#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<string, ii> si;

int getDiff(string cur, string from)
{
    int res = 0;
    if ((cur.length() != from.length()) || (cur == from))
        return res;

    // printf("%s %s\n", cur.c_str(), from.c_str());
    for (int i = 0; i < (int)cur.length(); i++) {
        if (cur[i] != from[i])
            res++;
    }

    return res;
}

void solve()
{
    // read to dictionary
    vector<string> s;

    char input[1000];
    while (fgets(input, 1000, stdin) != NULL && input[0] != '*') {
        if (input[0] == ' ')
            continue;
        input[strlen(input) - 1] = '\0';
        s.push_back(input);
    }

    char from[100], to[100];
    while (fgets(input, 1000, stdin) != NULL && input[0] != '\n') {
        sscanf(input, "%s %s", from, to);
        // printf("%s %s\n", from, to);
        queue<si> q;

        int out[(int)s.size()];
        memset(out, -1, sizeof(out));
        q.push(si(from, ii(0, -1)));
        while (q.size() > 0) {
            string cur = q.front().first;
            int cnt = q.front().second.first;
            int par = q.front().second.second;
            q.pop();

            for (int i = 0; i < (int)s.size(); i++) {
                if (s[i] == cur) {
                    out[i] = 1;
                    break;
                }
            }

            // printf("%s %d\n", cur.c_str(), cnt);

            if (cur == (string)to) {
                printf("%s %s %d\n", from, to, cnt);
                break;
            }

            for (int i = 0; i < (int)s.size(); i++) {
                if (i == par)
                    continue;
                if (out[i] == 1)
                    continue;
                if (getDiff(s[i], cur) == 1) {
                    q.push(si(s[i], ii(cnt + 1, i)));
                }
            }
        }
    }
}

int main()
{
    int ncase;
    char input[1000];
    fgets(input, 1000, stdin);
    sscanf(input, "%d", &ncase);

    while (ncase--) {
        solve();
        if (ncase != 0)
            printf("\n");
    }

    return 0;
}
