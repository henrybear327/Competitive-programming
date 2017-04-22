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
        int n, m;
        scanf("%d %d", &n, &m);

        bool possible[200010] = {0};
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);

            for (int j = 200010 - 1; j >= 0; j--) {
                if (j - num >= 0 && possible[j - num] == true)
                    possible[j] = true;
            }
            possible[num] = true;
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            int num;
            scanf("%d", &num);

            if (possible[num] == true)
                ans++;
        }
        printf("%d\n", ans);
    }
}