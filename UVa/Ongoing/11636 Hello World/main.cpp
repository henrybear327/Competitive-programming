#include <cstdio>

int main()
{
	int n, cnt = 1;
	while(scanf("%d", &n) == 1 && n > 0) {
		int i = 0;
		while( (1 << (i + 1)) <= n)
			i++;
		if( (1 << i) < n)
			i++;
		printf("Case %d: %d\n", cnt++, i);
	}

	return 0;
}
