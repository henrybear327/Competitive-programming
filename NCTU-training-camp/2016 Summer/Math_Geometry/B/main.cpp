#include <bits/stdc++.h>

using namespace std;

int main()
{	
    int p[4];
    for(int i = 0; i < 4; i++)
	scanf("%d", &p[i]);

    sort(p, p + 4);
    
    int level = 0;
    do {    
	int a = p[0], b = p[1], c = p[2];
	if(a + b > c && a + c > b && b + c == a && level == 0)
	    level = 1;
	if(a + b > c && a + c > b && b + c > a)
	    level = 2;
    } while(next_permutation(p, p + 4));

    if(level == 0)
	printf("IMPOSSIBLE\n");
    else if(level == 1)
	printf("SEGMENT\n");
    else
	printf("TRIANGLE\n");

    return 0;
}
