#include <cstdio>

using namespace std;

const int dx[2] = {0, 1}; // N, E
const int dy[2] = {1, 0}; // N, E

int M, N;
void move(int& x, int& y, int e, int n, int f, int t, int who)
{
	if(t > f) // out of fuel
		return;
	
	// x y e n f
	// 2 0 9 2 100
	int dir;
	int s = e + n;
	t %= s;
	if(t == 0)
		t = s;
	if(who == 1) {
		if(t <= n) 
			dir = 0;
		else
			dir = 1;
	} else {
		if(t <= e)
			dir = 1;
		else
			dir = 0;
	}
	// printf("who %d t %d n %d e %d dir %d\n", who, t, n, e, dir);

	x += dx[dir];
	y += dy[dir];

	if(x >= M)
		x = 0;
	if(y >= N)
		y = 0;
}

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		// M, N, X1, Y1, E1, N1, F1, X2, Y2, E2, N2, F2
		scanf("%d %d", &M, &N);

		int x1, y1, e1, n1, f1;
		int x2, y2, e2, n2, f2;
		scanf("%d %d %d %d %d", &x1, &y1, &e1, &n1, &f1); // N then E
		scanf("%d %d %d %d %d", &x2, &y2, &e2, &n2, &f2); // E then N
		
		int t = 1;
		bool error = false;

		while(1) {
			// printf("%d\n", t);

			move(x1, y1, e1, n1, f1, t, 1);
			move(x2, y2, e2, n2, f2, t, 2);
			// printf("1 -> %d %d\n", x1, y1);
			// printf("2 -> %d %d\n", x2, y2);
			
			if(x1 == x2 && y1 == y2) {
				error = true;
				break;
			}

			if(f1 < t && f2 < t) {
				break;
			}

			t++;
		}

		if(error == true) 
			printf("robots explode at time %d\n", t);
		else
			printf("robots will not explode\n");
	}

	return 0;
}

