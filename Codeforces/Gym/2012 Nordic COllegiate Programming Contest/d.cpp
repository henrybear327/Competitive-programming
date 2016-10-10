#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	char inp[10000];
	scanf("%s", inp);

	int len = strlen(inp);
	char holding = ' ';
	int diff = 0, ans = 0;
	for(int i = 0; i < len; i++) {
		int inc = inp[i] == 'W' ? 1 : -1;

		if(holding != ' ') {
			int inch = holding == 'W' ? 1 : -1;

			if( abs(diff + inch) <= n ) {
				holding = ' ';
				diff += inch;
				ans++;
			}
		}

		if( abs(diff + inc) > n) {
			if(holding != ' ') {
				break;
			} else {
				holding = inp[i];
			}	
		} else {
			diff += inc;
			ans++;
		}
	}

	printf("%d\n", ans);
	return 0;
}
