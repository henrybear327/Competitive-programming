#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

bool in(int x, int y)
{
	return (x - 50) * (x - 50) + (y - 50) * (y - 50) <= 50 * 50;
}

double dist(int x, int y)
{	
	double dx = x - 50, dy = y - 50;
	return sqrt(dx * dx + dy * dy);
}	

const double pi = acos(-1);
double getTheta(int x, int y)
{
	return 360 * acos((50.0 * y - 2500.0) / (50.0 * dist(x, y))) / (2 * pi);
}

int main()
{	
	int ncase;
	scanf("%d", &ncase);
	
	int cnt = 1;
	while(ncase--) {
		printf("Case #%d: ", cnt++);

		int percentage, x, y;
		scanf("%d %d %d", &percentage, &x, &y);
		
		if(in(x, y) == true) {
			double bound = 360.0 * percentage / 100.0;
			double theta = getTheta(x, y);
			if(x < 50)
				theta = 360.0 - theta;

			// printf("%f %f\n", bound, theta);

			if( bound - theta > -EPS ) {
				printf("black\n");
			} else {
				printf("white\n");
			}
		} else {
			printf("white\n");
		}
	}

	return 0;
}
