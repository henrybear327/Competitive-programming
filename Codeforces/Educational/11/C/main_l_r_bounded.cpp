#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int n, k;
int l, r;
bool check(int inp[], int fa)
{
    int cnt = 0;
    for(int i = 0; i < fa; i++) {
	if(inp[i] == 0)
	    cnt++;
    }
    if(cnt <= k) {
	l = 0;
	r = fa - 1;
	return true;
    }

    for(int i = fa; i < n; i++) {
	if(inp[i - fa] == 0)
	    cnt--;
	if(inp[i] == 0)
	    cnt++;
	if(cnt <= k) {
	    l = i - fa + 1;
	    r = i;
	    return true;
	}
    }

    return false;
}

int main()
{
    scanf("%d %d", &n, &k);
    
    int inp[n];
    l = -1; // bitch... init!!!
    r = -1;
    for(int i = 0; i < n; i++)
	scanf("%d", &inp[i]);

    // binary search the answer
    int lb = 0, ub = n; // [lb, ub]
    while(ub - lb > 1) {
	//printf("%d %d\n", lb, ub);
	int mid = (lb + ub) / 2;
	if(check(inp, mid) == false)
	    ub = mid - 1;
	else
	    lb = mid;
    }

    printf("%d\n", check(inp, ub) ? ub : lb);
    for(int i = 0; i < n; i++) {
	if(l <= i && i <= r) 
	    printf("1 ");
	else
	    printf("%d ", inp[i]);
    }

    return 0;
}
