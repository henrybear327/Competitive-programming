#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    char inp[10];
    scanf("%s", inp);

    sort(inp, inp + 4);
    if ((inp[0] == inp[1]) && (inp[2] == inp[3]) && (inp[0] != inp[2]))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
