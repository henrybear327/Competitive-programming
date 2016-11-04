#include <stdio.h>
#include <set>
#include <string>

using namespace std;

int m[5][5];

inline bool inBound(int x, int y)
{
	return (0 <= x && x < 5) && (0 <= y && y < 5);
}

string toString(int val)
{
	string res = "";
	res += (char)(val + '0');
	return res;
}

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
set<string> cnt;
void go(int x, int y, int step, string path)
{
	if(step == 6) {
		cnt.insert(path);
	} else {
		for(int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if(inBound(xx, yy)) {
				go(xx, yy, step + 1, path + toString(m[xx][yy]));
			}
		}
	}
}

int main()
{
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			scanf("%d", &m[i][j]);
	
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			string path = toString(m[i][j]);
			go(i, j, 1, path);
		}
	}

	printf("%d\n", (int)cnt.size());

	return 0;
}
