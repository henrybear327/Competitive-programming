#include <stdio.h>

int main()
{   
    printf("%d\n", (int)1e5);
    for(int i = 1; i < (int)1e5; i++)
	printf("%d\n", i);

    return 0;
}
