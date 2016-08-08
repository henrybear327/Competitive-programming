#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

const char* str[2] = {"I love ", "I hate "};

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		printf("%s", str[i % 2]);
		printf("%s", i != n ? "that " : "it");
	}
	
    return 0;
}
