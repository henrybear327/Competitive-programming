#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n, a;
	scanf("%d %d", &n, &a);

	if(n == 1) { // you are a bitch, come on!
		printf("0\n");
		return 0;
	}

	int inp[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &inp[i]);
	sort(inp, inp + n);
	
	int dl,dr, ans = INT_MAX;
	// case1
	dl = abs(a - inp[0]);
	dr = abs(a - inp[n - 2]);
	ans = min(ans, inp[n - 2] - inp[0] + min(dl, dr));

	// case2
	dl = abs(a - inp[1]);
	dr = abs(a - inp[n - 1]);
	ans = min(ans, inp[n - 1] - inp[1] + min(dl, dr));
	
	printf("%d\n", ans);
	
    return 0;
}
