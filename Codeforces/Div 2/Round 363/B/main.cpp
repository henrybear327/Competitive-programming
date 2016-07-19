#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

vector<int> cnt[1111];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
	
    int xcnt[1111] = {0}, ycnt[1111] = {0}, total;
    int g[n][m];
    memset(g, 0, sizeof(g));
    for(int i = 0; i < n; i++) {
	char inp[1111];
	scanf("%s", inp);
	for(int j = 0; j < m; j++) {
	    if(inp[j] == '*') {
		xcnt[i]++;
		ycnt[j]++;
		total++;
		g[i][j] = 1;
	    }
	}
    }
    
    int ansx, ansy = -1;
    for(int i = 0; ansy == -1 && i < n; i++) {
	for(int j = 0; j < m; j++) {
	    int cnt = xcnt[i] + ycnt[j] - g[i][j];
	    if(cnt != total)
		continue;
	    ansx = i;
	    ansy = j;
	    break;
	}
    }
    if(ansy == -1)
	printf("NO\n");
    else
	printf("YES\n%d %d\n", ansx + 1, ansy + 1);

    return 0;
}
