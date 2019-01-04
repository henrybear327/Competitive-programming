#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

typedef long long int ll;

using namespace std;

int main()
{
    char inp[100100];
    scanf("%s", inp);

    printf("%s", inp);
    
    reverse(inp, inp + strlen(inp));
    printf("%s\n", inp); 

    return 0;
}
