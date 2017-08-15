#include <bits/stdc++.h>
using namespace std;

struct Pos {
    bool del;
    int r, c;
};

const int L = (1 << 0);
const int D = (1 << 1);
const int R = (1 << 2);
const int U = (1 << 3);

const int MAX_S = 10;
int S, N, M, K, Q;
int maze[MAX_S][MAX_S];
vector<Pos> balls;
bool ball[MAX_S][MAX_S];
bool hole[MAX_S][MAX_S];
bool blue[MAX_S][MAX_S];
char cmd[40];
int ans;

inline int to_dec(char c) {
    if (c <= '9')
	return c - '0';
    return c - 'A' + 10;
}

void tilt(int dr, int dc, int need_wall1, int need_wall2) {
    auto cmp = [&](const Pos& a, const Pos& b) {
	if (need_wall1 == R)
	    return a.c > b.c;
	if (need_wall1 == L)
	    return a.c < b.c;
	if (need_wall1 == U)
	    return a.r < b.r;
	if (need_wall1 == D)
	    return a.r > b.r;
	return false;
    };
    sort(balls.begin(), balls.end(), cmp);
    // printf("%d, %d\n", dr, dc);
    for (Pos& pos : balls) {
	if (pos.del) continue;

	while (true) {

	    int nr = pos.r + dr;
	    int nc = pos.c + dc;

	    if (maze[pos.r][pos.c] & need_wall1) {
		break;
	    }
	    if (maze[nr][nc] & need_wall2) {
		break;
	    }
	    if (ball[nr][nc]) {
		break;
	    }

	    if (hole[nr][nc]) {
		hole[nr][nc] = false;
		ball[pos.r][pos.c] = false;
		pos.del = true;
		break;
	    }

	    if (blue[nr][nc]) {
		ans++;
		blue[nr][nc] = false;
	    }

	    swap(ball[pos.r][pos.c], ball[nr][nc]);
	    pos.r = nr;
	    pos.c = nc;
	}
    }

   // for (Pos& pos : balls) {
   //	printf("(%d, %d), %d\n", pos.r, pos.c, pos.del);
   // }
   // puts("----");
}

int solve() {
    ans = 0;
    for (int i = 0; i < Q; i++) {
	if (cmd[i] == 'W') tilt(0, +1, R, L);
	if (cmd[i] == 'E') tilt(0, -1, L, R);
	if (cmd[i] == 'S') tilt(-1, 0, U, D);
	if (cmd[i] == 'N') tilt(+1, 0, D, U);
	//if (cmd[i] == 'E') tilt(0, +1, R, L);
	//if (cmd[i] == 'W') tilt(0, -1, L, R);
	//if (cmd[i] == 'N') tilt(-1, 0, U, D);
	//if (cmd[i] == 'S') tilt(+1, 0, D, U);
	//if (cmd[i] == 'N') tilt(+1, 0, D, U);
	//if (cmd[i] == 'S') tilt(-1, 0, U, D);
	//if (cmd[i] == 'E') tilt(0, +1, R, L);
	//if (cmd[i] == 'W') tilt(0, -1, L, R);
    }
    return ans;
}

int main() {
    int TC;
    scanf("%d", &TC);

    while (TC--) {
	scanf("%d %d %d %d %d", &S, &N, &M, &K, &Q);

	memset(maze, 0, sizeof(maze));
	memset(ball, false, sizeof(ball));
	memset(hole, false, sizeof(hole));
	memset(blue, false, sizeof(blue));
	balls.clear();

	for (int r = 0; r < S; r++) {
	    char inp[20];
	    scanf("%s", inp);

	    for (int c = 0; c < S; c++) {
		maze[r][c] = to_dec(inp[c]);
	    }
	}

	for (int i = 0; i < N; i++) {
	    int c, r; scanf("%d %d", &r, &c); c--; r--;
	    ball[r][c] = true;
	    balls.push_back((Pos) {false, r, c});
	}

	for (int i = 0; i < M; i++) {
	    int c, r; scanf("%d %d", &r, &c); c--; r--;
	    blue[r][c] = true;
	}

	for (int i = 0; i < K; i++) {
	    int c, r; scanf("%d %d", &r, &c); c--; r--;
	    hole[r][c] = true;
	}

	scanf("%s", cmd);
	printf("%d\n", solve());
    }

    return 0;
}