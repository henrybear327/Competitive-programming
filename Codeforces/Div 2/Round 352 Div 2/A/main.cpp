#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    string inp;
    for(int i = 1; i < 1000; i++) {
	if(i < 10)
	    inp += i + '0';
	else if(10 <= i && i <= 99) {
	    inp += ((i / 10) % 10) + '0';
	    inp += (i % 10) + '0';
	} else if(100 <= i && i <= 999) {
	    inp += ((i / 100) % 10) + '0';
	    inp += ((i / 10) % 10) + '0';
	    inp += (i % 10) + '0';
	}   
    }
    printf("%c\n", inp[n - 1]);
    
    return 0;
}
