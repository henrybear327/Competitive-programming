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

    int cnt = 0;
    for (int l = 0; l < n; l++) {
        int r = l;
        while (r + 1 < n && inp[l] == inp[r + 1])
            r++;
        cnt++;
        l = r;
    }
    printf("%d\n", cnt);

    return 0;
}
