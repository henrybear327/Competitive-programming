#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

int main()
{
    int n;
    scanf("%d", &n);

    // get binary rep.
    int k = 0, tmp = n, b_rep[35] = {0};
    while (tmp) {
        b_rep[k++] = tmp & 1;
        tmp >>= 1;
    }

    /*
       13 = 8 + 4 + 1 => 1101
     */
    reverse(b_rep, b_rep + k);
#if DEBUG == 1
    for (int i = 0; i < k; i++)
        printf("%d ", b_rep[i]);
    printf("\n");
#endif

    bool ans[1010][1010];
    memset(ans, false, sizeof(ans));

    // initial condition
    ans[1][3] = ans[3][1] = true;

    int cnt = 3; // last_node
    int total = 3;
    for (int i = 1; i < k; i++) {
        ans[cnt][total + 1] = ans[total + 1][cnt] = true;
        ans[cnt][total + 2] = ans[total + 2][cnt] = true;
        ans[total + 1][total + 3] = ans[total + 3][total + 1] = true;
        ans[total + 2][total + 3] = ans[total + 3][total + 2] = true;
        total += 3;
        cnt = total;
        if (b_rep[i] == 1) {
            int len = 2 * (i + 1) - 1;
            ans[1][cnt + 1] = ans[cnt + 1][1] = true;
            for (int j = 1; j < len - 1; j++) {
                ans[cnt + j][cnt + j + 1] = ans[cnt + j + 1][cnt + j] = true;
            }
            ans[cnt + len - 1][cnt] = ans[cnt][cnt + len - 1] = true;
            total += len - 1;
        }
    }

    // connect back to 2
    ans[2][cnt] = ans[cnt][2] = true;

    // print ans
    printf("%d\n", total);
#if DEBUG == 1
    printf("   ");
    for (int i = 1; i <= total; i++)
        printf("%3d", i);
    printf("\n");

    for (int i = 1; i <= total; i++) {
        printf("%3d", i);
        for (int j = 1; j <= total; j++) {
            printf("%3c", ans[i][j] == 1 ? 'Y' : 'N');
        }
        printf("\n");
    }
#endif

#if DEBUG == 0
    for (int i = 1; i <= total; i++) {
        for (int j = 1; j <= total; j++) {
            printf("%c", ans[i][j] == 1 ? 'Y' : 'N');
        }
        printf("\n");
    }
#endif

    return 0;
}
