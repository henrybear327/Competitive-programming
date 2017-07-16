#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, p;
multimap<double, int> data; // time left, which
int power[100100];          // power consumption of which

bool check(double mid)
{
	printf("%f\n", mid);
    // if more than two < 1
    printf("dist %d\n", distance(data.upper_bound(1.0), data.begin()));

    if (distance(data.upper_bound(1.0), data.begin()) > 1) {
		printf("false\n");
        return false;
	}

	printf("true\n");
    return true;
}

int main()
{
    scanf("%d %d", &n, &p);

    for (int i = 0; i < n; i++) {
        scanf("%d", &power[i]);

        int tmp;
        scanf("%d", &tmp);
        data.insert(make_pair(tmp / power[i], i));
    }

    double l = 0, r = 1e18;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;

        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    printf("%.15f\n", l);

    return 0;
}
