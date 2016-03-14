#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    
    int cnt[1000100] = {0};
    for(int i = 0; i < n; i++) {
	int tmp;
	scanf("%d", &tmp);

	cnt[tmp]++;
    }
    
    int ans = 0;
    for(int i = 0; i < 1000100 - 1; i++) {
	cnt[i + 1] += cnt[i] / 2;
	if(cnt[i] % 2 == 1) {
	    ans++;
	}
    }

    printf("%d\n", ans);

    return 0;
}
