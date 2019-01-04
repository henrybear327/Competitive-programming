#include <bits/stdc++.h>

using namespace std;

int cnt(char inp[111], int len)
{
	int res = 0;
	for(int i = 0; i < len - 1; i++)
		if(strncmp(inp + i, "VK", 2) == 0) {
			res++;
			i++;
		}

	return res;
}

int main()
{
	char inp[111];
	scanf("%s", inp);

	int ans = 0;
	int len = strlen(inp);
	
	for(int i = 0; i < len; i++) {
		// no change 
		ans = max(ans, cnt(inp, len));

		// change to K
		char tmp = inp[i];
		inp[i] = 'K';
		ans = max(ans, cnt(inp, len));
		inp[i] = tmp;

		// change to V
		inp[i] = 'V';
		ans = max(ans, cnt(inp, len));
		inp[i] = tmp;
	}
	printf("%d\n", ans);

	return 0;
}
