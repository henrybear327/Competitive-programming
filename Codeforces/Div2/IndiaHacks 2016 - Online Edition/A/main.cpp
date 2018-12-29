#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int cnt[1234] = {0};
    for(int i = 0; i < n; i++) {
	int tmp;
	scanf("%d", &tmp);
	cnt[tmp]++;
    }

    for(int i = 2; i <= 999; i++) {
	if((cnt[i - 1] > 0 && cnt[i] > 0) && (cnt[i] > 0 && cnt[i + 1] > 0)) {
	    printf("YES\n");
	    return 0;
	}   
    }
    printf("NO\n");
    return 0;
}
