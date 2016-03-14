#include <cstdio>
#include <cstring>

bool data[10001][10001];

int main()
{
    int h, l;
    while (scanf("%d %d", &h, &l) == 2 && h != 0 && l != 0) {
        memset(data, false, sizeof(data));

        // printf("h %d l %d\n", h, l);
        for (int i = 0; i < l; i++) {
            int tmp;
            scanf("%d", &tmp);
            tmp = h - tmp;

            for (int j = h - 1; j >= tmp; j--)
                data[j][i] = true;
        }

        /*
        printf("h %d l %d\n", h, l);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                printf("%d", data[i][j]);
            }
            printf("\n");
        }
        */

        int cnt = 0;
        for (int i = 0; i < h; i++) {
            bool flag = false;
            for (int j = 0; j < l; j++) {
                if (data[i][j] == false && flag == false) {
                    cnt++;
                    flag = true;
                } else if (data[i][j] == true && flag == true) {
                    flag = false;
                }
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}
