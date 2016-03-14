#include <bits/stdc++.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int cases;
    scanf("%d", &cases);

    int count = 1;
    while (cases--) {
        int array[3];
        for (int i = 0; i < 3; i++)
            scanf("%d", &array[i]);
        qsort(array, 3, sizeof(int), cmp);
        printf("Case %d: %d\n", count++, array[1]);
    }

    return 0;
}
