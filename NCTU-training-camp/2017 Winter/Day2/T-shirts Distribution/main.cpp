#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to, cap, rev;
    Edge(int a, int b, int c)
    {
        to = a;
        cap = b;
        rev = c;
    }
};

const int INF = 0x3f3f3f3f;
const int MAX_V = 1 + 1 + 6 + 100100;
vector<vector<Edge>> g(MAX_V);
int level[MAX_V];
int iter[MAX_V];

inline void add_edge(int u, int v, int cap)
{
    g[u].push_back((Edge) {
        v, cap, (int)g[v].size()
    });
    g[v].push_back((Edge) {
        u, 0, (int)g[u].size() - 1
    });
}

void bfs(int s)
{
    memset(level, -1, sizeof(level)); // 用fill
    queue<int> q;

    level[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < int(g[v].size()); i++) {
            const Edge &e = g[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f)
{
    if (v == t)
        return f;
    for (int &i = iter[v]; i < int(g[v].size()); i++) { // &很重要
        Edge &e = g[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t)   // dinic
{
    int flow = 0;
    for (;;) {
        bfs(s);
        if (level[t] < 0)
            return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

typedef pair<int, int> ii;

const char* shirts[] = {"S", "M", "L", "XL", "XXL", "XXXL"};

int main()
{
	int quantity[6];
	for(int i = 0; i < 6; i++) 
		scanf("%d", &quantity[i]);

	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		char inp[100];
		scanf("%s", inp);

		char *tmp = strtok(inp, ", ");
		while(tmp != NULL) {
			for(int j = 0; j < 6; j++) {
				if(strcmp(tmp, shirts[j]) == 0) {
					// printf("%s\n", tmp);
					add_edge(j + 1, 7 + i, 1);
					break;
				}
			}

			tmp = strtok(NULL, ", ");
		}

		add_edge(7 + i, 7 + n, 1);
	}

	for(int i = 1; i <= 6; i++) {
		if(quantity[i - 1] > 0)
			add_edge(0, i, quantity[i - 1]);
	}

	if(max_flow(0, 7 + n) == n) {
		printf("YES\n");

		map<int, int> ans;
		for(int i = 1; i <= 6; i++) {
			for(auto j : g[i]) {
				if(j.cap == 0 && j.to > 6) {
					ans[j.to] = i;
				}
			}
		}

		for(auto i : ans) {
			printf("%s\n", shirts[i.second - 1]);
		}
	} else {
		printf("NO\n");
	}

    return 0;
}
