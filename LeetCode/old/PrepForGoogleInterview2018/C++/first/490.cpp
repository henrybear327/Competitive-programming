#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

/*
[[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]
[0,4]
[4,4]
[[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]
[0,4]
[3,2]
[[0,0,0,0,1,0,0],[0,0,1,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,1],[0,1,0,0,0,0,0],[0,0,0,1,0,0,0],[0,0,0,0,0,0,0],[0,0,1,0,0,0,1],[0,0,0,0,1,0,0]]
[0,0]
[8,6]
*/

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

// handle special cases first
// [], "", ...
// range of input?

struct Data {
    int x, y;

    bool operator<(const Data &b) const
    {
        if (x == b.x) {
            return y < b.y;
        }
        return x < b.x;
    }

    bool operator!=(const Data &b) const
    {
        return !(x == b.x && y == b.y);
    }
};

class Solution
{
private:
    int n, m;
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    bool in(Data &data)
    {
        return (0 <= data.x && data.x < n) && (0 <= data.y && data.y < m);
    }

public:
    bool hasPath(vector<vector<int>> &maze, vector<int> &start,
                 vector<int> &destination)
    {
        // Use BFS
        // DFS will will have worse case that's really bad
        n = maze.size();
        if (n == 0)
            return false;
        m = maze[0].size();
        if (m == 0)
            return false;

        queue<Data> q;
        set<Data> seen;

        Data nxt = Data{start[0], start[1]};
        q.push(nxt);
        seen.insert(nxt);
        while (q.size() > 0) {
            Data &cur = q.front();
            q.pop();

            if (cur.x == destination[0] && cur.y == destination[1])
                return true;

            for (int i = 0; i < 4; i++) {
                nxt = Data{cur.x, cur.y};
                while (in(nxt) && maze[nxt.x][nxt.y] == 0) {
                    nxt.x += dx[i];
                    nxt.y += dy[i];
                }
                nxt.x -= dx[i];
                nxt.y -= dy[i];

                if (in(nxt) && nxt != cur && maze[nxt.x][nxt.y] == 0) {
                    if (seen.count(nxt) == 0) {
                        q.push(nxt);
                        seen.insert(nxt);
                    }
                }
            }
        }

        return false;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif