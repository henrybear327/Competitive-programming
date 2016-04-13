#include <cstdio>

int main()
{
	printf("1\n100,1,100,11\n");
	for(int i = 0; i < 100; i++) 
		for(int j = 0; j < 100; j++) 
			printf("%d%c", (j == i - 1 )||(j == i + 1) ? 1 : 0, j == 99 ? '\n' : ' ');
	
	return 0;
}
