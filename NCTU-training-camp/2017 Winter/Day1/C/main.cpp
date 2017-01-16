#include <bits/stdc++.h>

using namespace std;

vector<int> fib;
int sg[1111];

void gen()
{
	// generate fib
	fib.push_back(1);
	fib.push_back(2);
	for(int i = 2; ; i++) {
		fib.push_back(fib[i - 1] + fib[i - 2]);
		if(fib[i] > 1000)
			break;
	}
	
	// generate sg
	sg[0] = 0;
	sg[1] = 1;
	set<int> has;
	for(int i = 2; i < 1001; i++) {
		has.clear();
		for(int j = 0; j < (int)fib.size() && i - fib[j] >= 0; j++) {
			has.insert(sg[i - fib[j]]);
		}

		for(int j = 0; ; j++) {
			if(has.find(j) == has.end()) {
				sg[i] = j;
				break;
			}
		}
	}
	
	/*
	for(int i = 0; i < 10; i++)
		printf("%d %d\n", i, sg[i]);
	*/
}

int main()
{
	gen();
	int m, n, p;
	while(scanf("%d %d %d", &m, &n, &p) == 3 && (m || n || p)) {
		if((sg[m] ^ sg[n] ^ sg[p]) == 0)
			printf("Nacci\n");
		else
			printf("Fibo\n");
	}

	return 0;
}
