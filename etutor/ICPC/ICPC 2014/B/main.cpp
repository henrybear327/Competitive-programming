#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int par[1010];

int root(int x)
{
    return par[x] < 0 ? x : par[x] = root(par[x]);
}

void merge(int a, int b)
{
    if((a = root(a)) == (b = root(b)))
	return;

    if(par[a] > par[b])  // -3 -5 -> -5 -3
	swap(a,b);

    par[a] += par[b];
    par[b] = a;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while(ncase--) {
	memset(par, -1, sizeof(par));
	int cities, route;
	scanf("%d %d", &cities, &route);

	pair< int, pair<int, int> > inp[route];
	int total = 0;
	for(int i= 0; i < route; i++) {
	    scanf("%d %d %d", &inp[i].second.first,&inp[i].second.second, &inp[i].first);

	    total += inp[i].first;
	}

	sort(inp, inp + route);

	//MST
	int ans = 0;
	for(int i = 0; i < route; i++) {
	    if(root(inp[i].second.first) != root(inp[i].second.second)) {
		merge(inp[i].second.first, inp[i].second.second);
		ans += inp[i].first;
	    }
	}

	printf("%d\n",total - ans);
    }

    return 0;
}
