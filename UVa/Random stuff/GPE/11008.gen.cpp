#include <bits/stdc++.h>

using namespace std;

int main()
{
	srand(time(NULL));
	for(int i = 0; i < rand() % 10; i++)
		rand();
	int ncase = 10000;
	printf("%d\n", ncase);
	while(ncase--) {
		int n = 7, m = rand() % n + 1;
		printf("%d\n%d\n", n, m);

		set<pair<int, int>> has;
		for(int i = 0; i < n; i++) {
			int a = rand() % 20 - 10, b = rand() % 20 - 10;
			if(has.find({a, b}) != has.end())
				i--;
			else {
				has.insert({a, b});
				printf("%d %d\n", a, b);
			}
		}
	}

	return 0;
}	
