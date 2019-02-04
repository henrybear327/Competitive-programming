#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int num;
    scanf("%d", &num);

    int cnt = 0;
    while (num > 0) {
        if (num <= 3) {
            num = 0;
        } else {
            num -= 2;
        }
        cnt++;
    }

    printf("%d\n", cnt);
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
        solve();

    return 0;
}
