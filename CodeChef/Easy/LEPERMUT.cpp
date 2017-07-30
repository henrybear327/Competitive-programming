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
	
	int local = 0;
	for(int i = 0; i < n - 1; i++)
		if(inp[i] > inp[i + 1])
			local++;
	
	int global = 0;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++) {
			if(inp[i] > inp[j])
				global++;
	}

	printf("%s\n", local == global ? "YES" : "NO");
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
