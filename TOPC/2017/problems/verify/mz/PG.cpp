#include<bits/stdc++.h>

using namespace std;

int X;

inline bool xor_less(const int &x, const int &y)
{
	return (x^X) < (y^X);
}

void solve()
{
	int n, q;
	scanf("%d%d",&n,&q);
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	X = 0;
	while(q--)
	{
		int op, v;
		scanf("%d%d",&op,&v);
		if(op==1)
			X ^= v;
		else
		{
			sort(a.begin(),a.end(),xor_less);
			long long out = 0;
			for(int i = 0; i < v; i++)
				out+=a[i]^X;
			printf("%lld\n",out);
		}
	}
}

int main()
{
	int ncases;
	scanf("%d",&ncases);
	while(ncases--)
		solve();
}
