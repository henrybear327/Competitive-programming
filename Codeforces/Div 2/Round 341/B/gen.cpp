#include <cstdio>

int main()
{
    freopen("in.txt", "w", stdout);

    printf("200000\n");
    
    int cnt = 1;
    for(int i = 1; i <= 1000 && cnt <= 200000; i++) {
	for(int j = 1; j <= 1000 && cnt <= 200000; j++) {
	    printf("%d %d\n", i, j);
	    cnt++;
	}
    }

    return 0;
}
