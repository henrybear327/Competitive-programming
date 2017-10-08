#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int r, c;
bool inBound(int x, int y)
{
    return (0 <= x && x < r) && (0 <= y && y < c);
}

void solve(int ncase)
{
    printf("Case %d: ", ncase);

    int m, n;
    scanf("%d %d %d %d", &r, &c, &m, &n);

    int g[r][c];
    memset(g, 0, sizeof(g));

    int w;
    scanf("%d", &w);
    for (int i = 0; i < w; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        g[x][y] = 1;
    }
	
	// BE CAREFUL WHEN CREATING THIS TABLE!
	// (m, n) = (0, 7)
	// Traditional method will create duplicated entries for dx and dy
    set<ii> tmp;
    const int xFactor[4] = {1, 1, -1, -1};
    const int yFactor[4] = {1, -1, 1, -1};
    for (int i = 0; i < 4; i++) {
        tmp.insert(ii(m * xFactor[i], n * yFactor[i]));
        tmp.insert(ii(n * xFactor[i], m * yFactor[i]));
    }
	
	vector<int> dx, dy;
	for(auto i : tmp) {
		dx.push_back(i.first);
		dy.push_back(i.second);
	}

    queue<ii> q;
    set<ii> used;
	q.push(ii(0, 0));
    used.insert(ii(0, 0));

    int ans[r][c];
    memset(ans, -1, sizeof(ans));
    while (q.size() > 0) {
        ii cur = q.front();
        q.pop();

        int cnt = 0;
        for (int i = 0; i < (int)dx.size(); i++) {
            int xx = cur.first + dx[i];
            int yy = cur.second + dy[i];

            if (inBound(xx, yy) && g[xx][yy] == 0) {
                cnt++;
                if (used.find(ii(xx, yy)) == used.end()) {
                    used.insert(ii(xx, yy));
                    q.push(ii(xx, yy));
                }
            }
        }

        ans[cur.first][cur.second] = cnt;
    }

    int even = 0, odd = 0;
    // printf("\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            // printf("%3d ", ans[i][j]);
            if (ans[i][j] == -1)
                continue;

            if (ans[i][j] % 2 == 0)
                even++;
            else
                odd++;
        }
        // printf("\n");
    }
    printf("%d %d\n", even, odd);
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++)
        solve(i);

    return 0;
}
