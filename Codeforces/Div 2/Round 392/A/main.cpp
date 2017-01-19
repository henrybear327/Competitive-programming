#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	int n;
	scanf("%d", &n);
	
	int total = 0;
	int mx = 0;
	for(int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);

		total += num;
		mx = max(mx, num);
	}

	printf("%d\n", mx * n - total);
	
    return 0;
}
