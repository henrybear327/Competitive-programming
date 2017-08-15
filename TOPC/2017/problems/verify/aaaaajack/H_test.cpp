#include<bits/stdc++.h>
#define N 100100
using namespace std;
int par[N][20],dis[N][20];
long long sum[N];
int cnt[N];
int sz[N],dep[N];
bool del[N];
vector<int> g[N];
int f[N];
inline void set_n(int n){
	for(int i=1;i<=n;i++) f[i]=i;
}
inline void clear_n(int n){
	for(int i=1;i<=n;i++){
		g[i].clear();
		del[i]=false;
	}
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
inline void uni(int x,int y){
	f[find(x)]=find(y);
}
void build_sz(int u,int p){
	sz[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!del[v]&&v!=p){
			build_sz(v,u);
			sz[u]+=sz[v];
		}
	}
}
void build_lay(int u,int p,int d,int l,int c){
	dis[u][l]=d;
	par[u][l]=c;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!del[v]&&v!=p){
			build_lay(v,u,d+1,l,c);
			sz[u]+=sz[v];
		}
	}
}
void cen_dc(int u,int d){
	build_sz(u,-1);
	//puts("good");
	int tsz=sz[u],p=-1;
	bool flag=true;
	while(flag){
		flag=false;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(!del[v]&&v!=p&&sz[v]+sz[v]>tsz){
				p=u;
				u=v;
				flag=true;
				break;
			}
		}
	}
	build_lay(u,-1,0,d,u);
	del[u]=true;
	dep[u]=d;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!del[v]) cen_dc(v,d+1);
	}
}
bool vis[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,q,x,y,k;
		vector<int> v,touch;
		scanf("%d%d",&n,&q);
		set_n(n);
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			assert(x>=1&&x<=n&&y>=1&&y<=n);
			assert(find(x)!=find(y));
			uni(x,y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		cen_dc(1,0);
		/*for(int i=1;i<=n;i++){
			printf("%d: par:",i);
			for(int j=0;j<=dep[i];j++){
				printf(" %d",par[i][j]);
			}
			printf(" dis:");
			for(int j=0;j<=dep[i];j++){
				printf(" %d",dis[i][j]);
			}
			puts("");
		}*/
		for(int i=1;i<=n;i++) vis[i]=0;
		while(q--){
			scanf("%d",&k);
			while(k--){
				scanf("%d",&x);
				assert(x>=1&&x<=n);
				v.push_back(x);
				assert(!vis[x]);
				vis[x]=1;
			}
			for(int i=0;i<v.size();i++) vis[v[i]]=0;
			for(int i=0;i<v.size();i++){
				for(int j=0;j<=dep[v[i]];j++){
					x=par[v[i]][j];
					sum[x]+=dis[v[i]][j];
					cnt[x]++;
					if(j) sum[x]-=dis[v[i]][j-1];
					if(!vis[x]){
						vis[x]=1;
						touch.push_back(x);
					}
				}
			}
			long long ans=0;
			for(int i=0;i<touch.size();i++){
				x=touch[i];
				ans+=sum[x]*cnt[x]*2;
				sum[x]=0;
				cnt[x]=0;
				vis[x]=0;
			}
			touch.clear();
			v.clear();
			printf("%lld\n",ans);
		}
		clear_n(n);
	}
	return 0;
}