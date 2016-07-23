#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    int col[n] = {0}, row[n] = {0};
    int c = 0, r = 0;
    for(int i = 0; i < m; i++) {
	int x, y;
	scanf("%d %d", &x, &y);
	x--;
	y--;

	if(row[x] == 0) {
	    row[x] = 1;
	    r++;
	}
	if(col[y] == 0) {
	    col[y] = 1;
	    c++;
	}

	ll ans = (ll)(n - c) * (ll)(n - r);
	printf("%lld ", ans);
    }
	
    return 0;
}
