#include <bits/stdc++.h>

using namespace std;

#define N 1000100

int f[N], len;
char inp[N];

/*
void fail()
{
    f[0] = 0;
    int j = 0;
    for(int i = 1; i < len; i++) {
	if(inp[i] == inp[j]) {
	    f[i] = j + 1;
	    j++;
	} else {
	    while(j != 0 && inp[i] != inp[j]) {
		j = f[j - 1];
	    }

	    if(inp[i] == inp[j]) {
		f[i] = j + 1;
		j++;
	    } else
		f[i] = j;
	}
    }
}
*/

void fail()
{
    f[0] = 0;
    int j = 0;
    for(int i = 1; i < len; i++) {
	while(j != 0 && inp[i] != inp[j])
	    j = f[j - 1];

	if(inp[i] == inp[j]) 
	    j++;

	f[i] = j;
    }
}

int main()
{
    scanf("%s", inp);
    len = strlen(inp);

    fail();

    /*
       for(int i = 0; i < len; i++)
       printf("%c ", inp[i]);
       printf("\n");
       for(int i = 0; i < len; i++)
       printf("%d ", f[i]);
       printf("\n");
     */

    int ans = -1;
    for(int i = 0; i < len - 1; i++)
	if(f[i] == f[len - 1]) {
	    ans = f[i];
	    break;
	}
    if(ans == -1) {
	ans = f[f[len - 1] - 1];
    }

    if(ans != 0) {
	// printf("%d\n", ans);
	for(int i = 0; i < ans; i++)
	    printf("%c", inp[i]);
    } else
	printf("Just a legend\n");

    return 0;
}
