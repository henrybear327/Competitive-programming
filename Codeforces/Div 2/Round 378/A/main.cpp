#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

bool check(char c)
{
	return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}	

int main()
{
	char inp[111];
	inp[0] = 'A';
	scanf("%s", inp + 1);
		
	int len = strlen(inp);
	inp[len] = 'A';
	inp[len + 1] = '\0';
	len = strlen(inp);

	int prev = 0, ans = 0;
	for(int i = 0; i < len; i++) {
		if(check(inp[i])) {
			ans = max(ans, i - prev);
			prev = i;
		}
	}
	if(ans == 0)
		printf("%d\n", len - 1);
	else
		printf("%d\n", ans);
	
    return 0;
}
