#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    double k;
    scanf("%d %lf", &n, &k);

    if(n % 5 == 0 && k - (double) n - 0.5 >= -1e-9) {
	k -= ((double) n + 0.5);	
    } 

    printf("%.2f\n", k);

    return 0;
}
