#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int gcd(int x, int y)
{
    return x == 0 ? y : gcd(y % x, x);
}

int main()
{
    int n, ncase = 1;
    while(scanf("%d", &n) == 1 && n) {
	int x, y;
	vector< ii > inp;
	for(int i = 0; i < n; i++) {
	    scanf("%d %d", &x, &y);

	    inp.push_back( ii(x, y) );
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++) {
	    map< ii, int > cnt;
	    for(int j = 0; j < n; j++) {
		if(i == j)
		    continue;

		int dx = inp[j].first - inp[i].first;
		int dy = inp[j].second - inp[i].second;
		
		if(dx == 0) {
		    // vertical
		    cnt[ii(0, 1)]++;
		}
		else if(dy == 0) {
		    // horizontal
		    cnt[ii(1, 0)]++;
		} else if( dx * dy > 0) {
		    dx = abs(dx);
		    dy = abs(dy);
		    int g = gcd(dx, dy);
		    cnt[ii(dx / g, dy / g)]++;
		} else {
		    dx = abs(dx);
		    dy = abs(dy);
		    int g = gcd(dx, dy);
		    cnt[ii(-dx / g, -dy / g)]++;
		}
	    }

	    for(auto j : cnt) {
		ans = max(ans, j.second + 1);
	    }
	}
	
	if(ans >= 4)
	    printf("Photo %d: %d points eliminated\n", ncase++, ans);
	else
	    printf("Photo %d: 0 points eliminated\n", ncase++);
    }
	
    return 0;
}
