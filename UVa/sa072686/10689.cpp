#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct Matrix {
private:
	int r, c;

public:
	vector<vector<int>> matrix;

	Matrix(int _r, int _c)
	{
		r = _r;
		c = _c;
		matrix = vector<vector<int>>(r, vector<int>(c, 0));
	}
};

int mod;
Matrix operator*(const Matrix &a, const Matrix &b)
{
	Matrix matrix(a.matrix.size(), b.matrix[0].size());

	for (int i = 0; i < (int)a.matrix.size(); i++)       // a row
		for (int j = 0; j < (int)b.matrix[0].size(); j++)  // b col
			for (int k = 0; k < (int)b.matrix.size(); k++) { // inner driver
				matrix.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j] % mod;
				matrix.matrix[i][j] %= mod;
			}

	// for (int i = 0; i < a.matrix.size(); i++) {
	// 	for (int j = 0; j < b.matrix[0].size(); j++)
	// 		printf("%d ", matrix.matrix[i][j]);
	// 	puts("");
	// }
	return matrix;
}

Matrix operator^(const Matrix &a, int n)
{
	Matrix base(a.matrix.size(), a.matrix.size()),
	       ans(a.matrix.size(), a.matrix.size());
	ans.matrix[0][0] = ans.matrix[1][1] = 1;
	base = a;
	while (n > 0) {
		// printf("n %d\n", n);
		if (n & 1) {
			ans = base * ans;
		}

		base = base * base;
		n >>= 1;
	}

	return ans;
}

void solve()
{
	int a, b, n, m;
	scanf("%d %d %d %d", &a, &b, &n, &m);
	mod = 1;
	for (int i = 0; i < m; i++)
		mod *= 10;

	Matrix init(2, 1);
	init.matrix[0][0] = b;
	init.matrix[1][0] = a;
	Matrix square(2, 2);
	square.matrix[0][0] = square.matrix[0][1] = square.matrix[1][0] = 1;

	if (n == 0)
		printf("%d\n", a);
	if (n == 1)
		printf("%d\n", b);
	else {
		Matrix ans = (square ^ (n - 1)) * init;
		printf("%d\n", ans.matrix[0][0]);
	}
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
		solve();

	return 0;
}
