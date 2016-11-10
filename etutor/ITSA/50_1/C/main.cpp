#include<cstdio>

int main()
{
	int ncase;
	scanf("%d", &ncase);
	
	while(ncase--) {
		int n;
		scanf("%d", &n);
		
		double area = 0;
		double interval = 1.0 / n;
		for(int i = 1; i <= n; i++) {
			area += interval * (interval * i * interval * i);
		}	
		printf("%.4f\n", area);
	}

	return 0;
}
