#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while(ncase--) {
	char inp[100];
	scanf("%s", inp);

	int len = strlen(inp);
	if(len == 5) {
	    printf("3\n");
	} else {
	    const char *one = "one", *two = "two";
	    int s1 = 0, s2 = 0;
	    for(int i = 0; i < 3; i++) {
		if(one[i] == inp[i])
		    s1++;
		if(two[i] == inp[i])
		    s2++;
	    }
	    if(s1 >= 2)
		printf("1\n");
	    else
		printf("2\n");
	}
    }

    return 0;
}
