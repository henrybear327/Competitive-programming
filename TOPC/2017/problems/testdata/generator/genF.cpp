#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ft first
#define sd second
const long long int MOD = (1e+9)+7;

long long int TCs, TC;
long long int prime[10000];
bool check[10000];
long long int i, x, primes;

long long int N[2][35];
long long int M;
long long int factorial[2][10010];

typedef pair<long long int, long long int> PII;
typedef pair<long long int, PII> PIII;
map<PIII, int> mapTC;
vector<PIII> outputTC;

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

long long int PowerTC(long long int x, long long int p){
	if (p==0) return 1;
	if (p==1) return x;
	if (x==0) return 0;
	if (x==1) return 1;
	
	long long int ans = Power(x, p/2);
	ans = ans*ans;
	if (p&1) ans = ans*x;
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

long long int Solve(long long int a, long long int b, long long int M){
	memset(N, 0, sizeof(N));
	N[0][0] = a;
	N[1][0] = b;
	
	for (int i=0; i<2; i++) for (int x=1; N[i][x-1]; x++){
		N[i][x] = N[i][x-1]/M;
		N[i][x-1] %= M;
	}
	
	long long int ans = 1;
	for (int x=0; x<32; x++) ans = (ans*Compute(N[0][x], N[1][x]))%MOD;
	return ans;
}

long long int Rand(){
	long long int ans = 0;
	for (int i=30; i>=0; i--) if (rand()&1) ans |= (1<<i);
	return ans;
}

void PrintTC(long long int a, long long int b, long long int M){
	printf("%lld %lld %lld\n", a, b, M);
	PIII tmp; tmp.ft = a; tmp.sd.ft = b; tmp.sd.sd = M;
	mapTC[tmp] = 1;
	TCs--;
	return ;
}

void PrintShuffledTCs(){
	while(outputTC.size()){
		int x = Rand()%outputTC.size();
		printf("%lld %lld %lld\n", outputTC[x].ft, outputTC[x].sd.ft, outputTC[x].sd.sd);
		outputTC.erase(outputTC.begin()+x);
	}
	
	return ;
}

int main(){
	freopen("TC.in", "w", stdout);
	srand(time(0));
	mapTC.clear();
	
	/* Preprocessing */
	prime[0] = 2;
	primes = 1;
	for (i=3; i<10000; i+=2) if (!check[i]){
		prime[primes] = i;
		primes++;
		for (x=i*i; x<10000; x+=i) check[x] = 1;
	}
	
	factorial[0][0] = 1;
	factorial[1][0] = 1;
	for (i=1; i<=10000; i++){
		factorial[0][i] = (factorial[0][i-1]*i)%MOD;
		factorial[1][i] = Power(factorial[0][i], MOD-2);
	}
	
	TCs = 9998;
	printf("%lld\n", TCs);
	
	PrintTC(2, 1, 2); // 0
	PrintTC(4, 2, 5); // 6
	PrintTC(0, 0, 2); // 1
	PrintTC(0, (1LL<<31)-1, 2); // 0
	PrintTC((1LL<<31)-1, 0, 2); // 1
	PrintTC((1LL<<31)-1, 1, 2); // 1
	PrintTC(PowerTC(3, 19)-1, 1, 3); // 2
	PrintTC(8, 4, 3); // 4
	PrintTC(13, 11, 3); // 0
	PrintTC(23, 11, 5); // 18
	PrintTC((1LL<<31)-1, 1LL<<30, 2); // 1
	PrintTC((1LL<<31)-1, 3LL<<29, 2); // 1
	PrintTC((1LL<<31)-1, 3LL<<29, 3); // 0
	PrintTC(PowerTC(3, 19)-1, PowerTC(3, 18), 3); // 2
	PrintTC(PowerTC(3, 19)-1, PowerTC(3, 18)+PowerTC(3, 17), 3); // 4
	PrintTC(0, (PowerTC(3, 19)-1)/2, 3); // 0
	PrintTC(PowerTC(3, 19)-1, (PowerTC(3, 19)-1)/2, 3); // 524288
	PrintTC(PowerTC(5, 13)-1, (PowerTC(5, 13)-1)/4, 5); // 67108864
	PrintTC(PowerTC(5, 13)-1, (PowerTC(5, 13)-1)/2, 5); // 60693925
	PrintTC(PowerTC(7, 11)-1, (PowerTC(7, 11)-1)/2, 7); // 998566407
	PrintTC(9972, 4986, 9973); // 340843642
	PrintTC(PowerTC(9973, 2)-1, (PowerTC(9973, 2)-1)/2, 9973); // 478603455
	PrintTC(PowerTC(9973, 2)-1, (PowerTC(9973, 2)-1)/2-1, 9973); // 279189256
	PrintTC(9941*9941-1, 9941*4969+4968, 9941); // 979078339
	
	outputTC.clear();
	
	for (TC=1; TC<=TCs; TC++){
		PIII tmp;
		
		if (TC<700){
			while(1){
				tmp.ft = Rand()%20;
				tmp.sd.ft = Rand()%20;
				tmp.sd.sd = prime[Rand()%8];
				if (mapTC.find(tmp)!=mapTC.end()) continue;
				mapTC[tmp] = 1;
				
				long long int ans = Solve(tmp.ft, tmp.sd.ft, tmp.sd.sd);
				if (TC%10){
					if (ans==0) continue;
					if (ans==1) continue;
				}
				
				outputTC.pb(tmp);
				break;
			}
			continue;
		}
		
		while(1){
			tmp.ft = Rand();
			tmp.sd.ft = Rand();
			tmp.sd.sd = prime[Rand()%primes];
			if (mapTC.find(tmp)!=mapTC.end()) continue;
			mapTC[tmp] = 1;
			
			long long int ans = Solve(tmp.ft, tmp.sd.ft, tmp.sd.sd);
			if (TC<8000) if (TC%10) if (ans==0) continue;
			if (TC<6000) if (TC%20) if (ans==1) continue;
			
			outputTC.pb(tmp);
			break;
		}
		
	}
	
	PrintShuffledTCs();
	
	/* Trash Input */
	puts("1");
	puts("2 2 2");
	puts("0");
	puts("0");
	
	return 0;
}


