#include <cstdio>

int main()
{
    int a, b;
    int k, n;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &k, &n);

    int da[a], db[b];
    for (int i = 0; i < a; i++)
        scanf("%d", &da[i]);
    for (int i = 0; i < b; i++)
        scanf("%d", &db[i]);

    int max = da[k - 1], index = b;
    for (int i = 0; i < b; i++) {
        if (db[i] > max) {
            index = i;
            break;
        }
    }

    if (b - index >= n)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
