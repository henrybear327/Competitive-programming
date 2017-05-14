#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    while (n--) {
        int num;
        scanf("%d", &num);

        int cnt = 0;
        for (; num != 0; num /= 10)
            if (num % 10 == 4)
                cnt++;
        printf("%d\n", cnt);
    }

    return 0;
}
