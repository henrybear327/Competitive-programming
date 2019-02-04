#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    cin >> n;

    string inp[n];
    for (int i = 0; i < n; i++)
        cin >> inp[i];

    int ans = 0;
    map<int, int> left, right;
    int zero = 0;
    for (int i = 0; i < n; i++) {
        stack<char> s;
        for (auto j : inp[i]) {
            if (s.size() > 0 && s.top() == '(' && j == ')')
                s.pop();
            else
                s.push(j);
        }

        int l = 0, r = 0;
        while (s.size() > 0) {
            if (s.top() == '(')
                l++;
            else
                r++;
            s.pop();
        }

        if (l != 0 && r != 0) {

        } else if (l != 0)
            left[l]++;
        else if (r != 0)
            right[r]++;
        else {
            zero++;
        }
    }

    for (auto i : left) {
        ans += min(i.second, right[i.first]);
    }
    ans += zero / 2;

    printf("%d\n", ans);

    return 0;
}
