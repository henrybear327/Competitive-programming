#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const long double PI = 3.14159265358979323846;

long double check(long double r, int n, int inp[])
{
	long double total = 0;
	for(int i = 0; i < n; i++) {
		long double S = inp[i];
		long double tmp = 1.0 - ((S * S) / (2 * r * r));
		// printf("%f\n", tmp);
		total += acos(tmp);
	}
	
	return total;
}

void solve()
{
	int n;
	long double C;
	scanf("%Lf %d", &C, &n);
	
	// 2 Pi r = C
	long double R = C / 2.0 / PI;

	int inp[n], mx = INT_MIN;
	for(int i = 0; i < n; i++) { 
		scanf("%d", &inp[i]);

		mx = max(mx, inp[i]);
	}

	// for(int i = 0; i < n; i++)
		// printf("%d\n", inp[i]);
	
	long double lowerBound = (long double)mx / 3, upperBound = 2 * R; 
	for(int i = 0; i < 200; i++) {
		long double mid = (lowerBound + upperBound) / 2;
		// printf("%.18Lf %.18Lf %.18Lf\n", lowerBound, mid, upperBound);

		if(check(mid, n, inp) < (2.0 * PI)) {
			upperBound = mid;
		} else {
			lowerBound = mid;
		}
	}

	// printf("%f %f\n", lowerBound, upperBound);
	long double circleArea = C * C / 4.0 / PI;
	// printf("%.18Lf %.18Lf\n", C, PI);
	long double polygonArea = 0.0;
	for(int i = 0; i < n; i++) {
		long double s = ((long double)inp[i] + lowerBound + lowerBound) / 2.0;
		// printf("%f\n", s);
		polygonArea += sqrt(s * (s - (long double)inp[i]) * (s - lowerBound) * (s - lowerBound));
	}
	
	// printf("%.18Lf %.18Lf\n", circleArea, polygonArea);
	printf("%.18Lf\n", circleArea - polygonArea);
}

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		solve();
	}

	return 0;
}
