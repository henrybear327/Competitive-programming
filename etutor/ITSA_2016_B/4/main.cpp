#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        int n;
        scanf("%d", &n);
        int sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int w;
            scanf("%d", &w);

            ans += (sum + (w / 2));
            sum += w;
        }

        printf("%d\n", ans);
    }
}