#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

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
const int MAX_V = 1 + 1 + 40 * 100;
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
    memset(level, -1, sizeof(level));
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
    for (int &i = iter[v]; i < int(g[v].size()); i++) {
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

int max_flow(int s, int t)
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

bool p[45000];
vector<int> prime;
void gen()
{
    fill(p, p + 45000, true);
    p[0] = false;
    p[1] = false;
    for (ll i = 2; i < 45000; i++) {
        if (p[i] == true) {
            prime.push_back(i);
            for (ll j = i * i; j < 45000; j += i) {
                p[j] = false;
            }
        }
    }
    /*
    for(int i = 0; i < 10; i++)
            printf("%d\n", prime[i]);
    */
}

int main()
{
    gen();

    int n, m;
    scanf("%d %d", &n, &m);

    // get all original numbers and factorize them
    int num[n];
    vector<ii> factor[n];
    int internal_nodes_left = 0;
    int internal_nodes_right = 0;

    vector<int> left_base;
    vector<int> right_base;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);

		bool is_prime = true;
        int tmp = num[i];

		if (i % 2 == 0) {
			left_base.push_back(internal_nodes_left);
		} else {
			right_base.push_back(internal_nodes_right);
		}

        for (int j = 0; tmp != 1 && j < (int)prime.size(); j++) {
            int cnt = 0;
            while (tmp % prime[j] == 0) {
				is_prime = false;
                tmp /= prime[j];
                cnt++;
            }

            if (cnt > 0)
                factor[i].push_back(ii(prime[j], cnt));

			if (i % 2 == 0) {
				internal_nodes_left += cnt;
			} else {
				internal_nodes_right += cnt;
			}
        }

		if(is_prime == true) {
			int cnt = 1;
			factor[i].push_back(ii(num[i], cnt));

			if (i % 2 == 0) {
                internal_nodes_left += cnt;
            } else {
                internal_nodes_right += cnt;
            }
		}

		/*
        printf("%d\n", num[i]);
        for(int j = 0; j < (int)factor[i].size(); j++) {
                printf("num %d has %d\n%c", factor[i][j].first, factor[i][j].second,
        j == (int)factor[i].size() - 1 ? '\n' : '\0');
        }
        if(i % 2 == 0) {
                printf("internal base %d\n", left_base[i / 2]);
        } else {
                printf("internal base %d\n", right_base[i / 2]);
        }
		*/
    }

    // printf("left_in %d right_in %d\n", internal_nodes_left,
    // internal_nodes_right);

    // s = total_internal_nodes, t = total_internal_nodes
    int total_internal_nodes = internal_nodes_left + internal_nodes_right;

    // get all pairing and create the graph
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--;
        y--;

        if (x % 2 == 1)
            swap(x, y);

        int left_offset = left_base[x / 2];
        int right_offset = internal_nodes_left + right_base[y / 2];
        // printf("lo %d ro %d\n", left_offset, right_offset);

        for (int i = 0; i < (int)factor[x].size(); i++) {
            for (int j = 0; j < (int)factor[y].size(); j++) {
                if (factor[x][i].first == factor[y][j].first) {
                    for(int p = 0; p < factor[x][i].second; p++) {
						for(int q = 0; q < factor[y][j].second; q++) {
							add_edge(left_offset + p, right_offset + q, 1);
						}
					}
                }

                right_offset += factor[y][j].second;
            }
            left_offset += factor[x][i].second;
        }
    }

	/*
	int sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < (int)factor[i].size(); j++) {
			sum += factor[i][j].second;
		}
	}
	assert(sum == total_internal_nodes);
	*/

    for (int i = 0; i < internal_nodes_left; i++) {
        add_edge(total_internal_nodes, i, 1);
        // printf("2 %d %d\n", total_internal_nodes, i);
    }

    for (int i = 0; i < internal_nodes_right; i++) {
        add_edge(internal_nodes_left + i, total_internal_nodes + 1, 1);
        // printf("3 %d %d\n", internal_nodes_left + i, total_internal_nodes + 1);
    }

    printf("%d\n", max_flow(total_internal_nodes, total_internal_nodes + 1));

    return 0;
}
