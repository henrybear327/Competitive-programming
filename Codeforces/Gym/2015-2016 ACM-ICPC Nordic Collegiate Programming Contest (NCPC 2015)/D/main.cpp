#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
    int n, k;
    while(scanf("%d %d", &n, &k) == 2) {
	vector<ii> inp;
	for(int i = 0; i < n; i++) {
	    int t;
	    scanf("%d", &t);
	    inp.push_back(ii(t, 1));
	    inp.push_back(ii(t + 1000, 0));
	}
	sort(inp.begin(), inp.end());
	
	int cnt = 0, mx = 0;
	for(int i = 0; i < (int)inp.size(); i++) {
	    if(inp[i].second == 1)
		cnt++;
	    else
		cnt--;
	    mx = max(mx, cnt);
	    //printf("%d %d\n", cnt, mx);
	}
	//printf("%d %d\n", mx / k, mx % k);
	printf("%d\n", mx / k + (mx % k == 0 ? 0 : 1));
    }

    return 0;
}
