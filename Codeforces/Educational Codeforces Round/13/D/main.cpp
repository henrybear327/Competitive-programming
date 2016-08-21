#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

const ll M = ((ll)1e9 + 7);

ll a, b, x, n;

struct matrix {
	ll data[2][2];
	
	matrix() { // default constructor
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				data[i][j] = 0;
	}

	matrix operator * (matrix q) { // overload *
		matrix ans;
		for (int i = 0; i < 2; i++) 
			for (int j = 0; j < 2; j++) 
				for (int k = 0; k < 2; k++) 
					ans.data[i][j] = (ans.data[i][j] + (data[i][k] * q.data[k][j]) % M) % M;
		return ans;
	}

	matrix operator *= (matrix q) { // overload *=
		matrix ans;
		for (int i = 0; i < 2; i++) 
			for (int j = 0; j < 2; j++) 
				for (int k = 0; k < 2; k++) 
					ans.data[i][j] = (ans.data[i][j] + (data[i][k] * q.data[k][j]) % M) % M;
		memcpy(data, ans.data, sizeof(ans.data));
		return ans;
	}	
};

ll fast_pow(ll exp)
{
	matrix base;
	base.data[0][0] = a;
	base.data[0][1] = b;
	base.data[1][1] = 1;

    // res = base ^ n
	matrix res;
	res.data[0][0] = res.data[1][1] = 1;
    while (exp) {
        if (exp & 1) {
            res *= base;
        }
        base *= base;
        exp >>= 1;

    };

    // res1 = res * [x, 1]
    ll res1 = (res.data[0][0] * x % M + res.data[0][1]) % M;
    return res1 % M;
}

int main()
{
    scanf("%lld %lld %lld %lld", &a, &b, &n, &x);

    // fast pow
    printf("%lld\n", fast_pow(n));

    return 0;
}
