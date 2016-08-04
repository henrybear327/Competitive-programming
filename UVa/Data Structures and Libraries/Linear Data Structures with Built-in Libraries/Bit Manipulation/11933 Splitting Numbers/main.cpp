#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n) == 1 && n != 0) {
		int pos = 32 - __builtin_clz(n) - 1;
		int a = 0, b = 0;
		int cnt = 0;
		for(int i = pos; i >= 0; i--) {
			if(n & (1 << i)) {
				if(cnt % 2 == 0) // to b
					b |= (1 << i);
				else
					a |= (1 << i);
				cnt++;
			}
		}
		
		if(__builtin_popcount(n) % 2 == 1)
			swap(a, b);
		printf("%d %d\n", a, b);
	}

	return 0;
}
