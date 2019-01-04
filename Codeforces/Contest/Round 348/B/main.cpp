#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    char inp[n + 10];
    scanf("%s", inp);
    
    int len[n];
    for(int i = 0; i < n; i++) 
	scanf("%d", &len[i]);

    bool seen[n];
    memset(seen, false, sizeof(seen));
    
    int c = 0;
    while((0 <= c && c < n) && seen[c] == false) {
	seen[c] = true;
	c += inp[c] == '>' ? len[c] : -1 * len[c];
    }
    
    if(!(0 <= c && c < n))
	printf("FINITE\n");
    else
	printf("INFINITE\n");

    return 0;
}
