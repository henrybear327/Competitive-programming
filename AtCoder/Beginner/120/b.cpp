#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    vector<int> ok;
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= min(a, b); i++) {
        if (a % i == 0 && b % i == 0)
            ok.push_back(i);
    }

    int k;
    scanf("%d", &k);
    reverse(ok.begin(), ok.end());
    printf("%d\n", ok[k - 1]);

    return 0;
}
