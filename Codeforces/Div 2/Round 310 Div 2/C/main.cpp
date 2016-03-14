#include <cstdio>
#include <cstdlib>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main()
{
    int total, chain;
    scanf("%d %d", &total, &chain);

    int cuts = 0, consecutive_one = 0;
    for (int i = 0; i < chain; i++) {
        int len;
        scanf("%d", &len);
        cuts += (len - 1);

        int prev = 1;
        bool is_one = false;
        for (int j = 0; j < len; j++) {
            int temp;
            scanf("%d", &temp);
            if (temp == 1) {
                is_one = true;
                continue;
            }
            if (is_one == true && temp == prev + 1) {
                prev++;
                consecutive_one++;
            } else {
                is_one = false;
            }
        }
    }

    printf("%d\n", cuts + total - 1 - consecutive_one * 2);

    return 0;
}
