#include<bits/stdc++.h>
#define N 100100
using namespace std;
long long a[N];
int nxt[40][N],sum[40][N];
int main(){
	int T,big=0;
	scanf("%d",&T);
	while(T--){
		int n,q,s=0,tp;
		long long x;
		scanf("%d%d",&n,&q);
		if(n+q>200) big++;
		for(int i=1;i<=n;i++){
			assert(a[i]>=0);
			scanf("%lld",&a[i]);
			assert(a[i]>=0&&a[i]<(1LL<<31));
		}
		sort(a+1,a+n+1);
		for(int l=0;l<=30;l++){
			int pre=0,now=-1;
			for(int i=1;i<=n;i++){
				if(a[i]&(1LL<<l)){
					sum[l][i]=sum[l][i-1]+1;
				}
				else{
					sum[l][i]=sum[l][i-1];
				}
				if(i>1&&(a[i]>>l)!=(a[i-1]>>l)){
					nxt[l][pre]=i-1;
					pre=i-1;
				}
			}
			nxt[l][pre]=n;
		}
		while(q--){
			scanf("%d%lld",&tp,&x);
			assert(tp==1||tp==2);
			int cnt[40]={};
			long long ans=0;
			if(tp==1){
				assert(x>=0&&x<(1LL<<31));
				s^=x;
			}
			else{
				assert(x<=n);
				int now=0,k=x,st=0,ed=n;
				for(int l=30;l>=0 && x>0;l--){
					if(nxt[l][st]<ed){
						int mid=nxt[l][st];
						if(s&(1<<l)){
							if(x>=ed-mid){
								for(int i=0;i<=30;i++){
									cnt[i]+=sum[i][ed]-sum[i][mid];
								}
								x-=ed-mid;
								ed=mid;
							}
							else{
								st=mid;
							}
						}
						else{
							if(x>=mid-st){
								for(int i=0;i<=30;i++){
									cnt[i]+=sum[i][mid]-sum[i][st];
								}
								x-=mid-st;
								st=mid;
							}
							else{
								ed=mid;
							}
						}
					}
				}
				for(int i=0;i<=30;i++){
					cnt[i]+=sum[i][st+x]-sum[i][st];
					assert(cnt[i]<=k);
					if(s&(1<<i)) ans+=1LL*(k-cnt[i])<<i;
					else ans+=1LL*cnt[i]<<i;
				}
				printf("%lld\n",ans);
			}
		}
	}
	assert(big<=5);
	fprintf(stderr,"%.2f seconds\n",1.0*clock()/CLOCKS_PER_SEC);
	return 0;
}