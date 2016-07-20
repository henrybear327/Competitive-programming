#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 9;
int n, i, a, b, ar[MAX], q[MAX], t;
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
        cin >> ar[i], m[ar[i]] = 1;
    for (int i = 0; i < n; i++)
        if (!m[a - ar[i]])
            m[ar[i]] = 2, q[++t] = ar[i];
    for (int i = 1; i <= t; i++)
        if (!m[b - q[i]])
            return cout << "NO", 0;
        else if (m[b - q[i]] != 2)
            m[b - q[i]] = 2, m[a - b + q[i]] = 2, q[++t] = a - b + q[i];
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << m[ar[i]] - 1 << " ";

    return 0;
}
