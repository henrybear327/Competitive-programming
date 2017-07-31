#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, d, r;
    while (scanf("%d %d %d", &n, &d, &r) == 3 && (n || d || r)) {
        int morning[n], evening[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &morning[i]);
        sort(morning, morning + n);

        for (int i = 0; i < n; i++)
            scanf("%d", &evening[i]);
        sort(evening, evening + n);
        reverse(evening, evening + n);

        int over = 0;
        for (int i = 0; i < n; i++)
            if (d < morning[i] + evening[i])
                over += morning[i] + evening[i] - d;

        printf("%d\n", over * r);
    }

    return 0;
}