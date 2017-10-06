#include <bits/stdc++.h>

using namespace std;

int main()
{
    char inp[111];
    scanf("%s", inp);
    
    for(int i = 0; i <= strlen(inp); i++)
        if(i == 4)
            printf(" ");
        else
            printf("%c", inp[(i < 4 ? i : i - 1)]);
    printf("\n");
    
    return 0;
}