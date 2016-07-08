#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int s[n + 1];
    for(int i = 1; i <= n; i++) 
	scanf("%d", &s[i]);

    int d[n + 1];
    for(int i = 1; i <= n; i++)
	d[i] = i - 1;

    for(int i = 1; i <= n; i++) {
	if(s[i] != i) {
	    if(d[i] + 1 < d[s[i]]) {
		for(int j = s[i]; j <= n; j++) {
		    if(d[j] < d[i] + 1 + j - s[i])
			break;
		    d[j] = d[i] + 1 + j - s[i];
		}
	    }
	}
    }

    for(int i = 1; i <= n; i++)
	printf("%d%c", d[i], i == n ? '\n' : ' ');

    return 0;
}
