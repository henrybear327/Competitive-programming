int nsp(int s,int t, int b, int *leng) { // th enum of shortest path from s to t, with node b
    int que[N],qf,qt,vis[N],i,np[N],d[N];
    int v,dist;
    for (i=0;i<n;i++) vis[i]=0;
    for (i=0;i<n;i++) np[i]=0;
    for (i=0;i<n;i++) d[i]=-1;
    que[0]=s;qf=0;qt=1;vis[s]=1;np[s]=1;
    if (b>=0) vis[b]=1;
    d[s]=0;
    while (qf<qt) {
        v=que[qf++];
        if (v==t) break;
        for (i=0;i<n;i++) {
            if (a[v][i]==1) {
                if (vis[i]==0) {
                    d[i]=d[v]+1;
                    vis[i]=1;
                    que[qt++]=i;
                }
                if (d[i]==d[v]+1) np[i]+=np[v];
            }
        }
    }
    *leng=d[t];
    return np[t];
}
