#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);
    
    char inp[200100];
    scanf("%s", inp);
    
    int pos[n];
    for(int i = 0; i < n; i++) 
	scanf("%d", &pos[i]);
    
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
	if(i - 1 >= 0) {
	    if(inp[i - 1] == 'R' && inp[i] == 'L')
		ans = min(ans, (pos[i] - pos[i - 1]) / 2);
	} 
	if(i + 1 < n) {
	    if(inp[i + 1] == 'L' &&  inp[i] == 'R')
		ans = min(ans, (pos[i + 1] - pos[i]) / 2);
	}
    }	

    printf("%d\n", ans == INT_MAX ? -1 : ans);
	
    return 0;
}
