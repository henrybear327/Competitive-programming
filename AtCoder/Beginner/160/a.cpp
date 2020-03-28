#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    char inp[10];
    scanf("%s", inp);

    if ((inp[2] == inp[3]) && (inp[4] == inp[5]))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
