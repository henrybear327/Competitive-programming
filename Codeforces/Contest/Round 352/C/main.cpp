#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

double dist(int x1, int y1, int x2, int y2)
{
    ll dx = x2 - x1;
    ll dy = y2 - y1;
    double res = sqrt(dx * dx + dy * dy);
    return res;
}

int main()
{   
    int x[3];
    int y[3];
    for(int i = 0; i < 3; i++)
	scanf("%d %d", &x[i], &y[i]);

    int n;
    scanf("%d", &n);
    
    double ans = 0;
    vector< pair<double, int > > aa;
    vector< pair<double, int > > bb;

    for(int i = 0; i < n; i++) {
	int a, b;
	scanf("%d %d", &a, &b);

	double d = dist(a, b, x[2], y[2]);

	aa.push_back(make_pair(dist(x[0], y[0], a, b) - d, i));
	bb.push_back(make_pair(dist(x[1], y[1], a, b) - d, i));
	
	ans += 2 * d;
    }
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    
    double tmp = min(aa[0].first, bb[0].first);
    for(int i = 0; i < min(3, (int)aa.size()); i++)
	for(int j = 0; j < min(3, (int)bb.size()); j++) {
	    if(aa[i].second != bb[j].second) {
		tmp = min(tmp, aa[i].first + bb[j].first);
	    }
	}

    printf("%.15f\n", ans + tmp);

    return 0;
}
