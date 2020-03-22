#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (a + b + c >= 22)
        printf("bust\n");
    else
        printf("win\n");

    return 0;
}
