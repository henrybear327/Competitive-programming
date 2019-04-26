#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    double sum = 0;
    while (n--) {
        double num;
        char kind[111];
        scanf("%lf %s", &num, kind);

        if (kind[0] == 'J')
            sum += num;
        else
            sum += num * 380000.0;
    }

    printf("%.15f\n", sum);

    return 0;
}
