#include <bits/stdc++.h>

using namespace std;

int n, m;
char hor[100];
char ver[100];

bool seen[100][100];
bool bound(int x, int y)
{
    return (0 <= x && x < n) && (0 <= y && y < m);
}

typedef pair<int, int> ii;
map<char, ii> key;
void dfs(int x, int y)
{
    if(seen[x][y])
	return;
    seen[x][y] = true;

    char h = hor[x];
    int xx = x + key[h].first, yy = y + key[h].second;
    if(bound(xx, yy))
	dfs(xx, yy);

    char v = ver[y];
    xx = x + key[v].first, yy = y + key[v].second;
    if(bound(xx, yy))
	dfs(xx, yy);
}

bool check()
{
    for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	    if(seen[i][j] == false)
		return false;
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    
    scanf("%s", hor);
    scanf("%s", ver);

    // ><v^
    key['>'] = ii(0, 1);
    key['<'] = ii(0, -1);
    key['v'] = ii(1, 0);
    key['^'] = ii(-1, 0);
    
    bool ok = true;
    for(int i = 0; i < n && ok; i++) {
	for(int j = 0; j < m && ok; j++) {
	    memset(seen, false, sizeof(seen));
	    dfs(i, j);

	    ok = check();
	}
    }

    if(ok)
	printf("YES\n");
    else
	printf("NO\n");

    return 0;
}
