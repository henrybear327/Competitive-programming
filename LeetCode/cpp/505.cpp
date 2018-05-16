#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

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
class Solution
{
private:
	const int dx[4] = {0, 0, 1, -1};
	const int dy[4] = {1, -1, 0, 0};

	int n, m;
	bool in(int x, int y)
	{
		return (0 <= x && x < n) && (0 <= y && y < m);
	}

	struct Position {
		int x, y, dir;
		int step;

		bool operator<(const Position &others) const
		{
			if (x == others.x) {
				if (y == others.y)
					return dir < others.dir;
				return y < others.y;
			}
			return x < others.x;
		}
	};

public:
	int shortestDistance(vector<vector<int>> &maze, vector<int> &start,
	                     vector<int> &destination)
	{
		n = maze.size();
		if (n == 0)
			return -1;
		m = maze[0].size();
		if (m == 0)
			return -1;

		queue<Position> q;
		set<Position> seen;
		for (int i = 0; i < 4; i++) {
			q.push(Position{start[0], start[1], i, 0});
			seen.insert(Position{start[0], start[1], i, 0});
		}

		while (q.size() > 0) {
			Position pos = q.front();
			q.pop();

			// cout << pos.x << " " << pos.y << " " << pos.dir << " " << pos.step
			//      << endl;

			int xx = pos.x + dx[pos.dir];
			int yy = pos.y + dy[pos.dir];

			if (in(xx, yy) && maze[xx][yy] == 0) {
				pos.x = xx;
				pos.y = yy;
				pos.step++;
				if (seen.count(pos) == 0) {
					seen.insert(pos);
					q.push(pos);
				}
			} else {
				if (pos.x == destination[0] && pos.y == destination[1])
					return pos.step;

				// try out other directions
				for (int i = 0; i < 4; i++) {
					if (pos.dir != i) {
						Position candidate{pos.x + dx[i], pos.y + dy[i], i, pos.step + 1};
						// cout << pos.x + dx[i] << " " << pos.y + dy[i] << " "
						//      << seen.count(candidate) << endl;
						if (in(pos.x + dx[i], pos.y + dy[i]) &&
						    maze[pos.x + dx[i]][pos.y + dy[i]] == 0 &&
						    seen.count(candidate) == 0) {
							// cout << pos.x + dx[i] << " " << pos.y + dy[i] << endl;
							seen.insert(candidate);
							q.push(candidate);
						}
					}
				}
			}
		}

		return -1;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif