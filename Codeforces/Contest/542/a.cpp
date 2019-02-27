#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int half = (n + 1) / 2;
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (num > 0)
            pos++;
        else if (num < 0)
            neg++;
    }

    if (pos >= half)
        printf("1\n");
    else if (neg >= half)
        printf("-1\n");
    else
        printf("0\n");

    return 0;
}
