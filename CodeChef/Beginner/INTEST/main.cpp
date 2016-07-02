#include <cstdio>

int main()
{
    int n, k;
    while(scanf("%d %d", &n, &k) == 2) {
	int cnt = 0;
	for(int i = 0; i < n; i++) {
	    int tmp;
	    scanf("%d", &tmp);

	    if(tmp % k == 0)
		cnt++;
	}
	printf("%d\n", cnt);
    }
    return 0;
}
