#include<bits/stdc++.h>
#define N 20010
#define Q 1000000007
using namespace std;
int fac[N],inv[N];
int qp(int a,int x){
	int r=1;
	while(x){
		if(x&1) r=1LL*r*a%Q;
		a=1LL*a*a%Q;
		x>>=1;
	}
	return r;
}
bool prime_test(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}
int main(){
	fac[0]=inv[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=1LL*fac[i-1]*i%Q;
		inv[i]=qp(fac[i],Q-2);
	}
	int T;
	long long a,b,m;
	bool fless=false;
	long long mx=0;
	int big=0;
	scanf("%d",&T);
	assert(T<=10000);
	while(T--){
		scanf("%lld%lld%lld",&a,&b,&m);
		assert(a<(1LL<<31)&&b<(1LL<<31));
		assert(m<10000&&m>0);
		assert(prime_test(m));
		a-=b;
		int ans=1,ar,br;
		if(a<0) ans=0,fless=true;
		mx=max(mx,min(a,b));
		if(a>1023456789&&b>1023456789) big++;
		//else ans=1LL*fac[a%m+b%m]*inv[a%m]%Q*inv[b%m]%Q;
		while(a>0&&b>0){
			ar=a%m;
			br=b%m;
			a/=m;
			b/=m;
			if(ar+br<m){
				ans=1LL*ans*fac[ar+br]%Q*inv[ar]%Q*inv[br]%Q;
			}
			else{
				ans=0;
				break;
			}
		}
		printf("%d\n",ans);
	}
	/*if(fless) fprintf(stderr,"Less\n");
	fprintf(stderr,"max value:%lld\n",mx);
	fprintf(stderr,"big test:%d\n",big);*/
	return 0;
}