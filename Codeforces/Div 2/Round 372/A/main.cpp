#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n, c;
	scanf("%d %d", &n, &c);
	
	int ans = 0, inp[n];
	for(int i = 0; i < n; i++) 
		scanf("%d", &inp[i]);
	
	ans = 1;
	for(int i = 1; i < n; i++) {
		if(inp[i] - inp[i - 1] > c)
			ans = 1;
		else
			ans++;
	}
	printf("%d\n", ans);
	
    return 0;
}
