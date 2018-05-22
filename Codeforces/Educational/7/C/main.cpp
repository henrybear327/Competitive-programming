#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

/*
Using prefix sum is wrong
7 1
2 1 3 2 2 2 2
1 7 2
*/

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    pair<int, int> inp[200010];
    for(int i = 1; i <= n; i++)
	scanf("%d", &inp[i].first);

    inp[n].second = n + 100;
    for(int i = n; i >= 1; i--) {
	if(inp[i].first != inp[i - 1].first)
	    inp[i - 1].second = i;
	else
	    inp[i - 1].second = inp[i].second;
    }
    /*
    for(int i = 1; i <= n; i++)
	printf("%d %d\n", inp[i].first, inp[i].second);
    */
    for(int i = 0; i < m; i++) {
	int l, r, x;
	scanf("%d %d %d", &l, &r, &x);

	if(inp[l].first != x)
	    printf("%d\n", l);
	else if(inp[l].second <= r)
	    printf("%d\n", inp[l].second);
	else
	    printf("-1\n");
    }

    return 0;
}
