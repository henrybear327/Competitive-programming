#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    char inp[10], ans[10];
    scanf("%s %s", inp, ans);

    int cnt = 0;
    for (int i = 0; i < 3; i++)
        if (inp[i] == ans[i])
            cnt++;

    printf("%d\n", cnt);

    return 0;
}
