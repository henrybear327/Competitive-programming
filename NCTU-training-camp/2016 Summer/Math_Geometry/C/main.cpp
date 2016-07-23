#include <bits/stdc++.h>
using namespace std;

double dist(int a, int b, int c, int d)
{   
    double dx = a - c;
    double dy = b - d;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    int px, py;
    scanf("%d %d", &px, &py);
    double ans = 0;
    for(int i = 0; i < n - 1; i++) {
	int x, y;
	scanf("%d %d", &x, &y);

	ans += dist(x, y, px, py);
	px = x;
	py = y;
    }

    printf("%.15f\n", ans * k / 50);
    
    return 0;
}
