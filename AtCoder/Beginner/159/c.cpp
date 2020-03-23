#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int l;
    scanf("%d", &l);

    double edge = l * 1.0 / 3;

    printf("%.15f\n", edge * edge * edge);

    return 0;
}
