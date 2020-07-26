#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);

    char inp[h][w + 2];
    for (int i = 0; i < h; i++) {
        scanf("%s", inp[i]);
    }

    int ans = 0;
    for (int i = 0; i < (1 << h); i++) {
        for (int j = 0; j < (1 << w); j++) {
            int cnt = 0;

            for (int x = 0; x < h; x++) {
                for (int y = 0; y < w; y++) {
                    if (inp[x][y] == '#' && ((i >> x) & 1) && ((j >> y) & 1))
                        cnt++;
                }
            }

            ans += (cnt == k);
        }
    }

    printf("%d\n", ans);

    return 0;
}
