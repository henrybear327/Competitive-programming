#include <bits/stdc++.h>
using namespace std;

int main()
{
    char inp[1000000]; // 10^(10^5) -> 10^k is 10 + k zeros
    scanf("%s", inp);
    
    int len = strlen(inp), num;
    if(len > 2)
	sscanf(inp + len - 2, "%d", &num);
    else
	num = atoi(inp);

    if(num % 4 == 0)
	printf("4\n");
    else
	printf("0\n");

    return 0;
}
