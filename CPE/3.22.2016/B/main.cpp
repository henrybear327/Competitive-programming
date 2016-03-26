#include <bits/stdc++.h>

using namespace std;

const char *keyboard[4] = {"`1234567890-=", 
			    "QWERTYUIOP[]\\",
			    "ASDFGHJKL;'", 
			    "ZXCVBNM,./"};

int main()
{
    char inp[10000];
    while(fgets(inp, 10000, stdin) != NULL) {
	for(int i = 0; inp[i] != '\0'; i++) {
	    bool ok = false;
	    for(int j = 0; j < 4 && ok == false; j++) {
		for(int k = 0; keyboard[j][k] != '\0'; k++) {
		    if(keyboard[j][k] == inp[i]) {
			ok = true;
			printf("%c", keyboard[j][k - 1]);
			break;
		    }
		}
	    }
	    if(ok == false)
		printf("%c", inp[i]);
	}
    }

    return 0;
}
