#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	const char* str = "aabb";
	for(int i = 0; i < n; i++)
		printf("%c", str[i % 4]);
	
	return 0;
}
