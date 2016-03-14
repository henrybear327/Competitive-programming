#include <bits/stdc++.h>

int main()
{
    int N, S;
    scanf("%d %d", &N, &S);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        ans += S % a;
        S /= a;
    }
    printf("%d\n", ans + S);
    return 0;
}
