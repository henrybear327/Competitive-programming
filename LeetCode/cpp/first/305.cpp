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
typedef pair<int, int> ii;
class UFDS
{
private:
	vector<vector<ii>> data;
	vector<vector<bool>> active;

	int group;

public:
	UFDS(int m, int n)
	{
		data = vector<vector<ii>>(m, vector<ii>(n, ii(1, -1)));
		active = vector<vector<bool>>(m, vector<bool>(n, false));

		group = 0;
	}

	void setActive(int x, int y)
	{
		active[x][y] = true;
		group++;
	}

	bool isActive(int x, int y)
	{
		return active[x][y];
	}

	ii root(int x, int y)
	{
		ii &ret = data[x][y];
		return ret.second == -1 ? ii(x, y) : ret = root(ret.first, ret.second);
	}

	int sz(int x, int y)
	{
		return root(x, y).first;
	}

	void merge(int x1, int y1, int x2, int y2)
	{

		ii r1 = root(x1, y1);
		ii r2 = root(x2, y2);

		if (r1 == r2)
			return;

		if (sz(r1.first, r1.second) < sz(r2.first, r2.second))
			swap(r1, r2);
		data[r1.first][r1.second].first += data[r2.first][r2.second].first;
		data[r2.first][r2.second] = r1;
		group--;
	}

	int getGroup()
	{
		return group;
	}
};

class Solution
{
private:
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};

public:
	vector<int> numIslands2(int m, int n, vector<pair<int, int>> &positions)
	{
		UFDS ufds(m, n);
		vector<int> ans;
		for (auto i : positions) {
			// cout << i.first << " " << i.second << endl;
			ufds.setActive(i.first, i.second);

			int x = i.first, y = i.second;
			for (int j = 0; j < 4; j++) {
				int xx = x + dx[j];
				int yy = y + dy[j];

				if ((0 <= xx && xx < m) && (0 <= yy && yy < n) &&
				    ufds.isActive(xx, yy)) {
					ufds.merge(x, y, xx, yy);
				}
			}
			// cout << ufds.getGroup() << endl;
			ans.push_back(ufds.getGroup());
		}

		return ans;
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif