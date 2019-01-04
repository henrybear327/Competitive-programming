#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	char inp[10000];
	int n, m;
	fgets(inp, 10000, stdin);
	sscanf(inp, "%d %d", &n, &m);

	bool color = false;
	for(int i = 0; i < n; i++) {
		fgets(inp, 10000, stdin);

		int len = strlen(inp);
		for(int j = 0; j < len; j++) {
			if(inp[j] == ' ')
				continue;
			if(inp[j] == 'C' || inp[j] == 'M' || inp[j] == 'Y')
				color = true;
		}
	}

	if(color)
		printf("#Color\n");
	else
		printf("#Black&White\n");

	return 0;
}
