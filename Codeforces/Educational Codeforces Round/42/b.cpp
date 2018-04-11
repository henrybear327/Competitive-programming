#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    char inp[n + 2];
    scanf("%s", inp);

    int ans = 0, turn = -1;
    for (int i = 0; i < n; i++) {
        if (inp[i] == '.') {
            int j = n;
            turn = (a >= b ? 0 : 1); // a 0 b 1
            for (j = i; j < n && inp[j] == '.'; j++) {
                if (turn == 0 && a > 0) {
                    ans++;
                    a--;
                } else if (turn == 1 && b > 0) {
                    ans++;
                    b--;
                }

                turn ^= 1;
            }
            i = j;
        }
    }

    printf("%d\n", ans);

    return 0;
}
