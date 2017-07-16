#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

void solve()
{
    int n;
    scanf("%d", &n);
	
	int inp[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &inp[i]);
	sort(inp, inp + n);
	
	int mn = INT_MAX;
	for(int i = 1; i < n; i++)
		mn = min(mn, inp[i] - inp[i - 1]);
	printf("%d\n", mn);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while (ncase--) {
        solve();
    }

    return 0;
}
