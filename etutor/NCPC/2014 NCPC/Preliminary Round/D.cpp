#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

double d(int a, int b, int c, int d)
{
    int dx = abs(c - a);
    int dy = abs(d - b);
    return sqrt((double)dx * dx + (double)dy * dy);    
}

int node;
int v[110];
int cnt[110];
int graph[110][110];
void dfs(int start)
{
    v[start] = 1;
   for(int i = 0; i < node; i++) {
	if(graph[start][i] == 1 && v[i] == 0) {
	    cnt[i]++;
	    dfs(i);
	}
   }
}

int main()
{
    while(scanf("%d", &node) == 1 && node) {
	vector< pair< pair<int, int>, int> > inp;

	for(int i = 0; i < node; i++) {
	    int a, b, r;
	    scanf("%d %d %d", &a, &b, &r);
	    inp.push_back(make_pair(make_pair(a, b), r));
	}

	memset(graph, 0, sizeof(graph));

	for(int i = 0; i < node; i++) {
	    for(int j = 0; j < node; j++) {
		if(i == j)
		    continue;

		int x1 = inp[i].first.first;
		int y1 = inp[i].first.second;
		int x2 = inp[j].first.first;
		int y2 = inp[j].first.second;

		int r = inp[i].second;

		if(d(x1, y1, x2, y2) <= r)
		    graph[i][j] = 1;
	    }
	}
	
	/*
	for(int i = 0; i < node; i++) {
	    for(int j = 0; j < node; j++) {
		printf("%d ", graph[i][j]);
	    }
	    printf("\n");
	}
	*/
	
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < node; i++) {
	    memset(v, 0, sizeof(v));
	    dfs(i);
	}
	
	int ans = 0;
	for(int i = 0; i < node; i++) {
	    	if(cnt[i] == node - 1)
		    ans++;
	}
	printf("%d\n", ans);
    }

    return 0;
}
