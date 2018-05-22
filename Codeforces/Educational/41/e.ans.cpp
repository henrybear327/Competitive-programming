#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
int n, a[N];

vector<int> vec[N];

struct FenwickTree {
    int sum[N];
    void init()
    {
        memset(sum, 0, sizeof(sum));
    }

    inline int lsb(int x)
    {
        return x & (-x);
    }

    int get(int x)
    {
        int res = 0;
        for (; x > 0; x -= lsb(x))
            res += sum[x];
        return res;
    }
    void update(int x)
    {
        for (; x <= n; x += lsb(x))
            sum[x]++;
    }

    void print()
    {
        printf("======\n");
        for (int i = 0; i <= n; i++)
            printf("%d %d\n", i, get(i));
    }
} fw;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] = min(a[i], n);
        vec[min(i - 1, a[i])].push_back(i);
    }

    // for (int i = 0; i <= n; i++) {
    //     printf("%d: ", i);
    //     for (auto j : vec[i])
    //         printf("%d ", j);
    //     puts("");
    // }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        fw.update(a[i]);
        for (auto j : vec[i]) {
            ans += fw.get(n) - fw.get(j - 1);
        }
        // fw.print();
    }
    printf("%lld\n", ans);

    return 0;
}