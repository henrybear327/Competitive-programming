#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

bool ask(int n)
{
    printf("%d\n", n);
    fflush(stdout);

    char inp[100];
    scanf("%s", inp);
    if(inp[0] == 'y') 
	return true;
    else
	return false;
}

void printPrime(bool yes)
{
    if(yes)
	printf("prime\n");
    else
	printf("composite\n");
}

int main()
{
    const int arr[4] = {2, 3, 5, 7};

    int prime = 0;
    bool yy[4] = {false};
    for(int i = 0; i < 4; i++) {
	if(ask(arr[i])) {
	    prime++;
	    yy[i] = true;
	}	
    }

    if(prime == 0)
	printPrime(true);
    else {
	if(prime >= 2)
	    printPrime(false); 
	else {
	    const int arr1[11] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	    if(yy[0]) {
		for(int i = 0; i < 11; i++) {
		    if(ask(arr1[i])) {
			printPrime(false);
			return 0;
		    }
		}
		if(ask(4) || ask(8) || ask(16) || ask(32) || ask(64)) {
		    printPrime(false);
		    return 0;
		}
	    } else if(yy[1]) {
		for(int i = 0; i <= 6; i++) {
		    if(ask(arr1[i])) {
			printPrime(false);
			return 0;
		    }
		}
		if(ask(9) || ask(27) || ask(81)) {
		    printPrime(false);
		    return 0;
		}
	    } else if(yy[2]) {
		for(int i = 0; i <= 3; i++) {
		    if(ask(arr1[i])) {
			printPrime(false);
			return 0;
		    }
		}
		if(ask(25)) {
		    printPrime(false);
		    return 0;
		}
	    } else {
		for(int i = 0; i <= 1; i++) {
		    if(ask(arr1[i])) {
			printPrime(false);
			return 0;
		    }
		}
		if(ask(49)) {
		    printPrime(false);
		    return 0;
		}
	    }

	    printPrime(true);
	}
    }

    return 0;
}
