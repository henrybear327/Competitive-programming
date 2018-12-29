#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int encode(ll num) 
{
	int res = 0;
	for(int i = 0; i < 18 && num; i++) {
		if(num % 2 == 1)
			res |= (1 << i);
		num /= 10;
	}

	return res;
}

int main()
{
	int n;
	scanf("%d", &n);

	map<int, int> cnt;
	for(int i = 0; i < n; i++) {
		char cmd[100];
		ll num;
		scanf("%s %lld", cmd, &num);

		int code = encode(num);
		if(cmd[0] == '+') {
			cnt[code]++;
		} else if(cmd[0] == '-') {
			cnt[code]--;
		} else {
			printf("%d\n", cnt[code]);
		}
	}
	
    return 0;
}
