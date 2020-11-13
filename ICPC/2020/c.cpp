#include <bits/stdc++.h>

using namespace std;

int table[10010][10010];
int main()
{
    int ncase;
    scanf("%d", &ncase);
    while(ncase--) {
        int n, k;
        scanf("%d %d", &n, &k);

        memset(table, 0, sizeof(table));
        int cur = 0;
        table[0][0] = k;
        for(int i = 1; i < n; i++) {
            //printf("1 i %d cur %d\n", i, cur);
            for(int j = 0; j < i; j++) {
                table[i][j] += (table[i - 1][j] + 1) / 2;
                table[i][j + 1] += table[i - 1][j] / 2;
            }

            //for(int j = 0; j <= i; j++)
              //  printf("%d ", table[i][j]);
            //printf("\n");

            if(table[i - 1][cur] % 2 == 1)
                cur = cur;
            else
                cur = cur + 1;
            //printf("2 i %d cur %d\n", i, cur);
        }

        printf("%d\n", cur);
    }

	return 0;
}
