#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int solve()
{
    int arr[3];
    for (int i = 0; i < 3; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + 3);

    return arr[1];
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for (int i = 1; i <= ncase; i++)
        printf("Case %d: %d\n", i, solve());

    return 0;
}
