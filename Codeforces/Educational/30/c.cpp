#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int matrix[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &matrix[i][j]);

    int mxScore = 0, replace = 0;
    for (int j = 0; j < m; j++) {
        int mx = 0, idx = 0;

        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += matrix[i][j];
        mx = sum;

        for (int i = k; i < n; i++) {
            sum += matrix[i][j];
            sum -= matrix[i - k][j];

            if (mx < sum) {
                mx = sum;
                idx = i - k + 1;
            }
        }

        mxScore += mx;
        for (int i = 0; i < idx; i++)
            replace += matrix[i][j];
    }

    printf("%d %d\n", mxScore, replace);

    return 0;
}
