#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

void solve()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	int cnt[10] = {0};

	for(int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		
		cnt[num]++;
	}

	for(int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		
		cnt[num]++;
	}

	int upper = 0;
	int lower = 0;
	for(int i = 0; i < 10; i++) {
		if(cnt[i] >= 1)
			lower++;
		
		if(cnt[i] >= 2)
			upper++;
	}
	
	if(upper * 2 > lower)
		printf("1\n");
	else
		printf("0\n");
}

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		solve();
	}

	return 0;
}
