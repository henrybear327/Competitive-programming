#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m; // pile, student
int box[100010];
bool check(ll limit)
{
	int b[100010];
	memcpy(b, box, sizeof(box));

		

	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i++) 
		scanf("%d", &box[i]);

	ll left = -1, right = LLONG_MAX - 10;
	while(right - left > 1) {
		ll mid = left + (right - left) / 2;
		
		// FFFFTTTT
		printf("%d %lld\n", check(mid), mid); 
		if(check(mid))
			right = mid;
		else
			left = mid;
	}
	printf("%lld\n", right);

	return 0;
}
