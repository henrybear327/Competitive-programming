#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    // return a == 0 ? b : gcd(b % a, a);
    return b == 0 ? a : gcd(b, a % b);
}

string solve()
{
    string ans;

    int n, l;
    scanf("%d %d", &n, &l);

    int inp[l];
    for (int i = 0; i < l; i++)
        scanf("%d", &inp[i]);

    int res[l + 1];
    int idx = -1;
    for (int i = 1; i < l; i++) {
        if (inp[i] == inp[i - 1]) // AAA or ABA
            continue;

        int g = gcd(inp[i - 1], inp[i]);
        idx = i;
        res[i] = g;
    }

    set<int> s;
    for (int i = idx - 1; i >= 0; i--)
        res[i] = inp[i] / res[i + 1];
    for (int i = idx + 1; i < l + 1; i++)
        res[i] = inp[i - 1] / res[i - 1];
    for (int i = 0; i < l + 1; i++)
        s.insert(res[i]);

    map<int, char> prime;
    assert(26 == s.size());
    auto it = s.begin();
    for (int i = 0; i < 26; i++) {
        prime[*it] = i + 'A';
        it++;
    }

    for (int i = 0; i < l + 1; i++) {
        ans += prime[res[i]];
    }

    return ans;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++) {
        auto res = solve();
        printf("Case #%d: %s\n", i, res.c_str());
    }
}
