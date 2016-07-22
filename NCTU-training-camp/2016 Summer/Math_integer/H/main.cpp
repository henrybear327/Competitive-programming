#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
	int a, b;
	scanf("%d %d", &a, &b);
    
	int ans = 0;
	while(a && b) {
	    if(a < b)
		swap(a, b);
	    ans += a / b;
	    a %= b;
	}
	printf("%d\n", ans);
    }

    return 0;
}
