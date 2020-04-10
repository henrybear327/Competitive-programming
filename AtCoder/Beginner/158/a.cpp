#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    char inp[10] = {'\0'};
    scanf("%s", inp);

    inp[3] = inp[0];
    bool ok = false;
    for (int i = 1; i < 4; i++)
        if (inp[i] != inp[i - 1])
            ok = true;

    if (ok)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
