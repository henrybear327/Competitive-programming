#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		int n;
		scanf("%d", &n);

		const int deniminations[] = {100, 50, 10, 5, 2, 1};
		int ans = 0;
		
		for(int i = 0; i < 6; i++) {
			while(n >= deniminations[i]) {
				n -= deniminations[i];
				ans++;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
