#include <bits/stdc++.h>

using namespace std;

#define N 100100
int main()
{
	char inp[N];
	scanf("%s", inp);

	int cnt[4] = {0}, len = strlen(inp);
	for(int i = 0; i < len; i++) {
		char c = inp[i];
		if(c == 'U')
			cnt[0]++;
		else if(c == 'D')
			cnt[1]++;
		else if(c == 'R')
			cnt[2]++;
		else
			cnt[3]++;
	}
	
	int a = abs(cnt[0] - cnt[1]);
	int b = abs(cnt[2] - cnt[3]);

	if((a + b) % 2 != 0)
		printf("-1\n");
	else
		printf("%d\n", (a + b) / 2);

	return 0;
}
