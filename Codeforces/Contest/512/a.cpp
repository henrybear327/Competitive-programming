#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n];
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &inp[i]);
        cnt1 += inp[i];
    }

    if (cnt1 > 0)
        printf("HARD\n");
    else
        printf("EASY\n");

    return 0;
}
