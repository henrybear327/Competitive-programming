nclude <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	m--;
	
	int inp[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &inp[i]);
	}
	
	int ans = INT_MAX;
	for(int i = m + 1; i < n; i++)
		if(inp[i] != 0 && inp[i] <= k) {
			ans = min(ans, 10 * (i - m));
			break;
		}
	
	for(int i = m - 1; i >= 0; i--)
		if(inp[i] != 0 && inp[i] <= k) {
			ans = min(ans, 10 * (m - i));
			break;
		}
	
	printf("%d\n", ans);

    return 0;
}
