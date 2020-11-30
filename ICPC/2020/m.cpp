#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while(ncase--) {
        int n, m;
        scanf("%d %d", &n, &m);

        bool x[2] = {false}, y[2] = {false};
        for(int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            x[num] = true;
        }
        for(int i = 0; i < m; i++) {
            int num;
            scanf("%d", &num);
            y[num] = true;
        }

        int ans = 0;
        for(int i = 1; i < 16; i++) {
            bool xx[2] = {false}, yy[2] = {false};
            for(int j = 0; j < 4; j++) {
                if((i >> j) & 1) {
                    xx[j / 2] = true;
                    yy[j % 2] = true;
                }
            }

            if(x[0] == xx[0] && x[1] == xx[1] && y[0] == yy[0] && y[1] == yy[1]) {
                ans++;
            }
        }

        printf("%d\n", ans);
    }

	return 0;
}
