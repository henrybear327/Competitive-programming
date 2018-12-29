#include <bits/stdc++.h>
//LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

int main()
{
    int v[4];
    for(int i = 0; i < 4; i++) {
	scanf("%d", &v[i]);
    }	    

    char input[100010];
    fgets(input, 100010, stdin);
    fgets(input, 100010, stdin);

    int ans = 0, len = strlen(input) - 1;
    for(int i = 0; i < len; i++) {
	ans += v[input[i] - '0' - 1];
    }
    printf("%d\n", ans);

    return 0;
}
