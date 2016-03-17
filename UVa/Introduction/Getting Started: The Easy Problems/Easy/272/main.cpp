#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool first = false;
    char inp[10000];
    while(fgets(inp, 10000, stdin) != NULL) {
	for(int i = 0; inp[i] != '\0'; i++) {
	    if(inp[i] == '"') {
		if(first == false) {
		    first = true;
		    printf("``");
		} else { 
		    first = false;
		    printf("''");
		}
	    } else {
		printf("%c", inp[i]);
	    }
	}
    }

    return 0;
}
