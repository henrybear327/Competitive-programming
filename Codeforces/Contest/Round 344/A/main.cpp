#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int a[n], b[n];
    for(int i = 0; i < n; i++)
	scanf("%d", &a[i]);

    for(int i = 0; i < n; i++) 
	scanf("%d", &b[i]);
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
	int x = a[i], y = b[i];
	ans = max(ans, x + y);
	for(int j = i + 1; j < n; j++) {
	    x |= a[j];
	    y |= b[j];
	    
	    ans = max(ans, x + y);
	}
    }

    printf("%d\n", ans);

    return 0;
}
