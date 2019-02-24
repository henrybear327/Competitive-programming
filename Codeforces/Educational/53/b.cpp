#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int pos[n + 1];
    for (int i = 0; i < n; i++) {
        int who;
        scanf("%d", &who);

        pos[who] = i;
    }

    int mx = -1;
    for (int i = 0; i < n; i++) {
        int who;
        scanf("%d", &who);

        if (pos[who] > mx) {
            printf("%d ", pos[who] - mx);
            mx = pos[who];
        } else {
            printf("0 ");
        }
    }

    return 0;
}
