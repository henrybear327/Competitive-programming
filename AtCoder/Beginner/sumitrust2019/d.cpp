#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    char inp[n + 3];
    scanf("%s", inp);

    int ans = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++) {
                char num[3];
                num[0] = i + '0';
                num[1] = j + '0';
                num[2] = k + '0';

                int cnt = 0;
                for (int p = 0; p < n; p++) {
                    if (inp[p] == num[cnt]) {
                        cnt++;
                        if (cnt == 3)
                            break;
                    }
                }

                if (cnt == 3)
                    ans++;
            }
    printf("%d\n", ans);

    return 0;
}
