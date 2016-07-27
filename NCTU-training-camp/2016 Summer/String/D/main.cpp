#include <bits/stdc++.h>

using namespace std;

#define prime 257
#define prime1 137
#define M 1000000007
#define M1 0xdefaced
#define N 600010

typedef long long ll;
ll p[N], p1[N];
void init()
{
	p[0] = p1[0] = 1;
	for(int i = 1; i < N; i++) {
		p[i] = p[i - 1] * prime % M;
		p1[i] = p1[i - 1] * prime1 % M1;
	}
}

ll getHash(string inp)
{
	ll res = 0;
	for(int i = 0; i < (int)inp.length(); i++)
		res = (res * prime % M + inp[i]) % M;
	
	return res;
}

ll getHash1(string inp)
{
	ll res = 0;
	for(int i = 0; i < (int)inp.length(); i++)
		res = (res * prime1 % M1 + inp[i]) % M1;
	
	return res;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	init();
	
	set<ll> s, s1;
	for(int i = 0; i < n; i++) {
		char inp[N];
		scanf("%s", inp);

		s.insert(getHash(inp));
		s1.insert(getHash1(inp));
	}

	for(int i = 0; i < m; i++) {
		char inp[N];
		scanf("%s", inp);
		
		bool ok = false;
		int len = strlen(inp);
		ll hashVal = getHash(inp);
		ll hashVal1 = getHash1(inp);
		for(int j = 0; !ok && j < len; j++) {
			for(char k = 'a'; !ok && k <= 'c'; k++) {
				// linearly try to change all position and check for hash
				if(inp[j] == k) 
					continue;
				if(s.find( ( (hashVal - inp[j] * p[len - j - 1] + M) % M + k * p[len - j - 1] ) % M) != s.end()) 
					if(s1.find( ( (hashVal1 - inp[j] * p1[len - j - 1] + M1) % M1 + k * p1[len - j - 1] ) % M1) != s1.end()) 
						ok = true;
			}
		}

		if(ok)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
