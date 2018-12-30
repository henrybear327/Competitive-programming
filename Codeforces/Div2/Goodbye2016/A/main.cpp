#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	int t = 0, ans = 1;
	while(1) {
		t += 5 * ans;

		if(t + k > 240)
			break;
		ans++;
	}
	ans--;

	printf("%d\n", min(ans, n)); // wow, bug
	
	return 0;
}
