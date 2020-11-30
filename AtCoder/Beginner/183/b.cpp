#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    double x1, y1, x2, y2;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

    if(x1 >= x2) {
        swap(x1, x2);
        swap(y1, y2);
    }

    printf("%.15f\n", x1 + (abs(x2 - x1) * (y1 / (y1 + y2))));

	return 0;
}
