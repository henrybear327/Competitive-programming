#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, w;
    scanf("%d %d", &n, &w);

    int inp[2 * n];
    for(int i = 0; i < 2 * n; i++) {
	scanf("%d", &inp[i]);
    }

    sort(inp, inp + 2 * n);

    int a = inp[0], b = inp[n];
    double x = min((double) w / (3.0 * n), min((double)a, (double)b / 2.0));

    printf("%.15f\n", 3 * x * n);

    return 0;
}
