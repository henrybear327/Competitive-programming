#include <bits/stdc++.h>

using namespace std;

int cmp(const void *a, const void *b)
{
    char *aa = (char*)a;
    char *bb = (char*)b;
    char ab[110], ba[110];
    strcpy(ab, aa);
    strcpy(ba, bb);
    strcat(ab, bb);
    strcat(ba, aa);

    return strcmp(ab, ba);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    char inp[n][60];
    for(int i = 0; i < n; i++)
	scanf("%s", inp[i]);

    qsort(inp, n, sizeof(inp[0]), cmp);
    
    for(int i = 0; i < n; i++)
	printf("%s", inp[i]);
    printf("\n");

    return 0;
}
