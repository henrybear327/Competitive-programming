#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    char inp[n + 3];
    scanf("%s", inp);

    for (int i = 0; i < n - 1; i++)
        if (inp[i] != inp[i + 1]) {
            printf("YES\n");
            printf("%c%c", inp[i], inp[i + 1]);
            return 0;
        }

    printf("NO\n");

    return 0;
}
