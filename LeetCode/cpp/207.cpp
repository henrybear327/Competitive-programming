// clang-format -style=LLVM -i *.cpp && astyle --style=linux *.cpp && rm *.orig
// && g++ -Wall -Wextra -std=c++11 ...

#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...

#endif

static int __initialSetup = []()
{
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}
();

class Solution
{
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<vector<int>> g(numCourses);
        int in_degree[numCourses];
        memset(in_degree, 0, sizeof(in_degree));
        for (int i = 0; i < (int)prerequisites.size(); i++) {
            int v = prerequisites[i].first;
            int u = prerequisites[i].second;

            in_degree[v]++;
            g[u].push_back(v); // u->v
        }

        // topological sort
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (in_degree[i] == 0)
                q.push(i);

        while (q.size() > 0) {
            int u = q.front();
            q.pop();

            for (auto v : g[u]) {
                in_degree[v]--;
                if (in_degree[v] == 0)
                    q.push(v);
            }
        }

        bool ok = true;
        for (int i = 0; i < numCourses; i++)
            if (in_degree[i] > 0)
                ok = false;

        return ok;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif