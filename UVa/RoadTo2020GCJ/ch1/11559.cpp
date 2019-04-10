#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, b, h, w;
    while (scanf("%d %d %d %d", &n, &b, &h, &w) != EOF) {
        int ans = INT_MAX;

        for (int i = 0; i < h; i++) {
            int perPerson;
            scanf("%d", &perPerson);

            for (int j = 0; j < w; j++) {
                int avail;
                scanf("%d", &avail);

                if (avail >= n && n * perPerson <= b) {
                    ans = min(ans, n * perPerson);
                }
            }
        }

        if (ans == INT_MAX)
            printf("stay home\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}
