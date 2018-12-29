#include <bits/stdc++.h>

using namespace std;

#define N 200100
vector<int> g[N];

int d[N], l[N];
void bfs()
{
    fill(d, d + N, INT_MAX);
    memset(l, 0, sizeof(l));
    d[1] = 0;

    queue<int> q;
    q.push(1);

    while(q.size() > 0) {
	int cur = q.front();
	q.pop();
	l[cur] = 1;

	for(auto i : g[cur]) {
	    if(l[i] == 1)
		continue;
	    d[i] = min(d[i], d[cur] + 1);
	    q.push(i);
	}
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int s[n + 1];
    for(int i = 1; i <= n; i++)
	scanf("%d", &s[i]);

    for(int i = 1; i < n; i++) {
	g[i].push_back(i + 1);
	g[i + 1].push_back(i);
    }

    for(int i = 1; i <= n; i++) {
	if(s[i] == i)
	    continue;
	g[i].push_back(s[i]);
    }

    bfs();

    for(int i = 1; i <= n; i++)
	printf("%d%c", d[i], i == n ? '\n' : ' ');
    
    return 0;
}
