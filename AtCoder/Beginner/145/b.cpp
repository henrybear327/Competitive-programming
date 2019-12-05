#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    if (n % 2 == 1) {
        printf("No\n");
        return 0;
    }

    char inp[n + 3];
    scanf("%s", inp);
    for (int i = 0; i < n / 2; i++) {
        if (inp[i] == inp[i + n / 2])
            continue;

        printf("No\n");
        return 0;
    }

    printf("Yes\n");

    return 0;
}
