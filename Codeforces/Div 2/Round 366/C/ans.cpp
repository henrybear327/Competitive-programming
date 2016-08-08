#include<bits/stdc++.h>
using namespace std;
const int MAX=4e5+9;
int n,q,ls,t,x,ans,c,b[MAX];
bool a[MAX];
vector<int> g[MAX];
int main()
{
	scanf("%d%d",&n,&q);
	while (q--)
	{
		scanf("%d%d",&t,&x);
		if (t==1) g[x].push_back(c),ans++,c++; else
			if (t==2)
			{
				for (int i=b[x];i<g[x].size();i++) ans-=!a[g[x][i]],a[g[x][i]]=1;
				b[x]=g[x].size();
			} else	for (;ls<x;ls++) ans-=!a[ls],a[ls]=1;
		printf("%d\n",ans);
	}
	return 0;
}
