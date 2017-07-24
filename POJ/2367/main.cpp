#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

vector<int> g[111];
int in[111];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int num;
        while (scanf("%d", &num) == 1 && num != 0) {
            g[i].push_back(num);
            in[num]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0)
            q.push(i);

    vector<int> ans;
    while (q.empty() == false) {
        int cur = q.front();
        q.pop();

        ans.push_back(cur);

        for (int i = 0; i < (int)g[cur].size(); i++) {
            in[g[cur][i]]--;
            if (in[g[cur][i]] == 0)
                q.push(g[cur][i]);
        }
    }

    for (int i = 0; i < (int)ans.size(); i++)
        printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');

    return 0;
}