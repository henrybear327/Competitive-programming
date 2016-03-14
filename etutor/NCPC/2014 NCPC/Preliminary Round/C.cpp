#include <cstdio>

int main()
{
    int cases;
    scanf("%d", &cases);
    printf("%d\n", cases);
    while(cases--) {
	int n;
	scanf("%d", &n);

	double a[n][n];
	for(int i = 0; i < n; i++) {
	    for(int j = 0; j < n; j++) {
		scanf("%lf", &a[i][j]);
	    }
	}

	double ans[n][n];
	for(int i = 0; i < n - 1; i++) {
	    for(int k = i + 1; k < n; k++) {
		int r = a[k][i]; //0?
		if(a[i][i]) {
		    r = a[k][i] / a[i][i];
		}
		for(int j = i + 1; j < n; j++) {
		    a[k][j] = a[k][j] - r * a[i][j];
		}
		a[k][i] = r;
	    }
	}
	
	printf("%d\n", n);
	for(int i = 0; i < n; i++) {
	    for(int j = 0; j < n; j++) {
		printf("%.1f%c", a[i][j], j == n - 1 ? '\n' : ' ');	
	    }
	}
    }	    

    return 0;
}
