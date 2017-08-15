#include<bits/stdc++.h>
using namespace std;

const long long int MOD = (1e+9)+7;

int TCs;
long long int N[2][35];
long long int M;
long long int factorial[2][10010];
long long int i, x;

long long int Power(long long int x, long long int p){
	if (p==0) return 1;
	if (p==1) return x;
	if (x==0) return 0;
	if (x==1) return 1;
	
	long long int ans = Power(x, p/2);
	ans = (ans*ans)%MOD;
	if (p&1) ans = (ans*x)%MOD;
	return ans;
}

long long int Compute(long long int a, long long int b){
	if (b>a) return 0;
	if (b==0) return 1;
	if (b==a) return 1;
	long long int ans = factorial[0][a];
	ans = (ans*factorial[1][b])%MOD;
	ans = (ans*factorial[1][a-b])%MOD;
	return ans;
}

int main(){
	factorial[0][0] = 1;
	factorial[1][0] = 1;
	for (i=1; i<=10000; i++){
		factorial[0][i] = (factorial[0][i-1]*i)%MOD;
		factorial[1][i] = Power(factorial[0][i], MOD-2);
	}
	
	scanf("%d", &TCs);
	while(TCs--){
		memset(N, 0, sizeof(N));
		
		for (i=0; i<2; i++) scanf("%d", &N[i][0]);
		scanf("%d", &M);
		
		for (i=0; i<2; i++){
			for (x=1; N[i][x-1]; x++){
				N[i][x] = N[i][x-1]/M;
				N[i][x-1] %= M;
			}
		}
		
		long long int ans = 1;
		for (x=0; x<32; x++) ans = (ans*Compute(N[0][x], N[1][x]))%MOD;
		printf("%d\n", ans);
	}
	
	return 0;
}


