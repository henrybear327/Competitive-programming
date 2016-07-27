#include <cstdio>
#include <cstring>

using namespace std;

#define N 10100
#define M 1000100
char pat[N];
char text[M];
int f[N];

void fail()
{
    int len = strlen(pat);
    
    f[0] = 0;
    int j = 0;
    for(int i = 1; i < len; i++) {
	while(j != 0 && pat[i] != pat[j])
	    j = f[j - 1];
	
	if(pat[i] == pat[j])
	    j++;
	
	f[i] = j;
    }
}

int match()
{
    int res = 0;
    
    int j = 0, plen = strlen(pat), tlen = strlen(text);

    for(int i = 0; i < tlen; i++) {
	while(j != 0 && text[i] != pat[j])
	    j = f[j - 1];
	
	
	if(text[i] == pat[j]) {
	    if(j == plen - 1) {
		res++;
		j = f[j];
	    } else { 
		j++;
	    }
	}
    }

    /*
    for(int i = 0; i < tlen; i++) {
	if(text[i] == pat[j]) {
	    if(j == plen - 1) {
		res++;
		j = f[j];
	    } else {
		j++;
	    }
	} else {
	    while(j != 0 && text[i] != pat[j])
		j = f[j - 1];

	    if(text[i] == pat[j])
		j++;
	}
    }
    */

    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
	scanf("%s", pat);
	scanf("%s", text);
	
	if(strlen(pat) > strlen(text)) {
	    printf("0\n");
	    continue;
	}

	fail();

	printf("%d\n", match());
    }

    return 0;
}
