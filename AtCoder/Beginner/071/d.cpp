// pretty good one
// 4 cases, just go through them carefully and write the code up

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

#define HORIZONTAL 0
#define VERTICAL 1

int main()
{
	int n;
	scanf("%d", &n);
	
	char inp[2][n];
	for(int i = 0; i < 2; i++) 
		scanf("%s", inp[i]);
	
	vector<int> t;
	for(int i = 0; i < n; i++) {
		if(inp[0][i] == inp[1][i]) {
			t.push_back(VERTICAL);
		} else {
			t.push_back(HORIZONTAL);
			i++;
		}
	}
	
	ll cnt = t[0] == HORIZONTAL ? 6 : 3;
	for(int i = 1; i < (int)t.size(); i++) {
		int prev = t[i - 1];
		int curr = t[i];

		if(prev == VERTICAL)
			cnt *= 2;
		else if(prev == HORIZONTAL && curr == HORIZONTAL)
			cnt *= 3;
		else
			cnt *= 1;
		cnt %= MOD;
	}
		
	printf("%lld\n", cnt);
	

	return 0;
}
