#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool bound(int x, int y)
{
	return (0 <= x && x < 8)&& (0 <= y && y < 8);
}

int main()
{
	char inp[100];
	scanf("%s", inp);

	int y = inp[0] - 'a';
	int x = inp[1] - '1';
	
	int ans = 0;
	for(int i = -1; i <= 1; i++) {
		for(int j = -1; j <= 1; j++) {
			if(i == 0 && j == 0)
				continue;

			if(bound(x + i, y + j))
				ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}
