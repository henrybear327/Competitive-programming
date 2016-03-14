#include <bits/stdc++.h>

using namespace std;

int A[5][5], B[5][5], C[5][5];
int cal(int x1, int y1, int x2, int y2)
{
    return C[x1][y1] = (C[x1][y1] *C[x2][y2] ) - (C[x1+1][y1] * C[x2-1][y2]);
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while(cases--) {
        int n;
        scanf("%d", &n);


        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int tmp;
                scanf("%d", &tmp);

                A[i][j] = tmp;
                B[j][i] = tmp;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int tmp = 0;
                for(int k = 0; k < n; k++) {
                    tmp += A[i][k] * B[k][j];
                }
                C[i][j] = tmp;
            }
        }

        int ans1 = 0;
        for(int i = 0; i < n; i++)
            ans1 += C[i][i];
        int ans = 0;
        for(int i = n - 2; i >= 0; i--) {
            ans = cal(i, i, i + 1, i + 1);
        }

        printf("%d %d\n", ans1, C[0][0]);

    }

    return 0;
}
