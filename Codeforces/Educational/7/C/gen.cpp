#include <cstdio>

int main()
{
    // freopen("in.txt", "w", stdout);
    printf("200000 1\n");
    for(int i = 0; i < 200000; i++)
	printf("1000000%c", i == 200000 - 1 ? '\n' : ' ');

    printf("1 200000 1000000\n");

    return 0;
}
