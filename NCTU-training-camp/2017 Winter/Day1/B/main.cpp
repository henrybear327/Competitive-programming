#include <bits/stdc++.h>

using namespace std;

int n, k;
int cal(int num)
{
    if (k % 2 == 0) {
        if (num < 3)
            return num;
        return num % 2 == 1 ? 0 : 1;
    } else {
        if (num <= 4)
            return num == 4 ? 2 : num % 2;
        if (num % 2 == 1)
            return 0;
        return cal(num / 2) == 1 ? 2 : 1;
    }
}

int main()
{
    scanf("%d %d", &n, &k);

    int val = 0;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        val ^= cal(num);
    }

    if (val == 0)
        printf("Nicky\n");
    else
        printf("Kevin\n");

    return 0;
}
