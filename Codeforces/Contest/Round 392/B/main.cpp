#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
	char inp[1000];
	scanf("%s", inp);
	
	int n;
	n = strlen(inp);
	char seq[4];
	for(int i = 0; i < n; i++) {
		if(inp[i] != '!') {
			seq[i % 4] = inp[i];
		}
	}
	
	int cnt[4] = {0};
	for(int i = 0; i < n; i++) {
		if(inp[i] == '!') {
			char c = seq[i % 4];
			if(c == 'R')
				cnt[0]++;
			else if(c == 'B')
				cnt[1]++;
			else if(c == 'Y')
				cnt[2]++;
			else
				cnt[3]++;
		}
	}

	for(int i = 0; i < 4; i++) 
		printf("%d%c", cnt[i], i == 3 ? '\n' : ' ');
	
    return 0;
}
