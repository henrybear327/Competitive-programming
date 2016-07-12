#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    char s[10];
    int x, y;
    vector< ii > inp[2];

    for(int i = 0; i < n; i++) {
	scanf("%s %d %d", s, &x, &y);
	
	if(s[0] == 'M')
	    inp[0].push_back(ii(x, y));
	else
	    inp[1].push_back(ii(x, y));
    }
    
    int mx = 0;
    for(int i = 1; i <= 366; i++) {
	int bc = 0, gc = 0;
	for(int j = 0; j < (int)inp[0].size(); j++) {
	    if(inp[0][j].first <= i && i <= inp[0][j].second)
		bc++;
	}

	for(int j = 0; j < (int)inp[1].size(); j++) {
	    if(inp[1][j].first <= i && i <= inp[1][j].second)
		gc++;
	}

	mx = max(mx, 2 * min(bc, gc));
    }

    printf("%d\n", mx);

    return 0;
}
