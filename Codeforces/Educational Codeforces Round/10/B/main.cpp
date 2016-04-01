#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int bit[200010];
#define LSB(x) (x&(-x))

int n;
void add(int x, int v)
{
    while(x <= n) {
	bit[x] += v;
	x += LSB(x);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    

    return 0;
}
