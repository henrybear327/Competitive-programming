// {{{ by shik
#if !defined(YCM) && 1
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("O3,no-stack-protector")
#pragma GCC target("tune=native")
// #include <stdio.h>
#endif
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#ifdef SHIK
template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0)

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T, size_t N>
ostream& operator <<( ostream &s, const array<T,N> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

template<typename T>
void _R( T &x ) { cin>>x; }
// void _R( int &x ) { scanf("%d",&x); }
void _R( int &x ) {
    int c;
    while ( (c=getchar_unlocked())<'0' || c>'9' );
    x=c-'0';
    while ( (c=getchar_unlocked())>='0' && c<='9' ) x=x*10+c-'0';
}
void _R( int64_t &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }

void R() {}
template<typename T, typename... U>
void R( T& head, U&... tail ) {
    _R(head);
    R(tail...);
}

template<typename T>
void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
void _W( const int64_t &x ) { printf("%" PRId64,x); }
template<typename T>
void _W( const vector<T> &x ) {
    for ( auto i=x.cbegin(); i!=x.cend(); i++ ) {
        if ( i!=x.cbegin() ) putchar(' ');
        _W(*i);
    }
}

void W() {}
template<typename T, typename... U>
void W( const T& head, const U&... tail ) {
    _W(head);
    putchar(sizeof...(tail)?' ':'\n');
    W(tail...);
}

template<typename T> inline bool chkmax( T &a, const T &b ) { return b>a ? a=b,true : false; }
template<typename T> inline bool chkmin( T &a, const T &b ) { return b<a ? a=b,true : false; }
template<typename T, typename F=less<T>>
inline void sort_uniq( vector<T> &v, F f=F() ) {
    sort(ALL(v),f);
    v.resize(unique(ALL(v))-v.begin());
}

template<typename T> using MaxHeap = priority_queue<T>;
template<typename T> using MinHeap = priority_queue<T,vector<T>,greater<T>>;

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif
// }}}}}}

constexpr int lg2( int x ) { return 31-__builtin_clz(x); }

const int N=1e5+10;
const int LGN=lg2(N)+1;
int n,m;
VI e[N];
void input() {
    R(n,m);
    REP1(i,1,n) e[i].clear();
    REP(i,n-1) {
        int a,b;
        R(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
}

int dep[N],fa[LGN][N],dt[N],ot[N],ts;
void dfs( int p, int f, int lv ) {
    dep[p]=lv;
    fa[0][p]=f;
    dt[p]=++ts;
    for ( int i:e[p] ) if ( i!=f ) dfs(i,p,lv+1);
    ot[p]=ts;
}

int lgn;
void lca_build() {
    for (int i = 0; i < lgn; i++) {
        for (int j = 1; j <= n; j++) {
            fa[i + 1][j] = fa[i][fa[i][j]];
        }
    }
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    int d = dep[b] - dep[a];
    int l = lg2(dep[b]);
    for (int i = 0; i <= l; i++) {
        if ((d >> i) & 1) b = fa[i][b];
    }
    if (a == b) return a;
    for (int i = lg2(dep[a]); i >= 0; i--) {
        if (fa[i][a] != fa[i][b]) {
            a = fa[i][a];
            b = fa[i][b];
        }
    }
    return fa[0][a];
}

void build() {
    ts=0;
    dfs(1,0,1);
    lgn=lg2(n);
    lca_build();
}

bool cmp_dt( int x, int y ) { return dt[x]<dt[y]; }

VI te[N];

int build_t( VI &q ) {
    sort(ALL(q),cmp_dt);
    VI stk;
    for ( int i:q ) {
        if ( stk.empty() || (dt[stk.back()]<=dt[i] && dt[i]<=ot[stk.back()]) ) {
            te[i].clear();
            stk.PB(i);
        } else {
            int p=lca(i,stk.back());
            while ( SZ(stk)>=2 && dep[stk[SZ(stk)-2]]>=dep[p] ) {
                int a=stk[SZ(stk)-2];
                int b=stk[SZ(stk)-1];
                te[a].PB(b);
                stk.pop_back();
            }
            if ( stk.back()!=p ) {
                te[p].clear();
                te[p].PB(stk.back());
                stk.back()=p;
            }
            te[i].clear();
            stk.PB(i);
        }
    }
    REP(i,SZ(stk)-1) te[stk[i]].PB(stk[i+1]);
    assert(!stk.empty());
    return stk[0];
}

bool inq[N];
LL ans,sz[N],dp[N];

void go( int p ) {
    sz[p]=inq[p];
    dp[p]=0;
    for ( int i:te[p] ) {
        go(i);
        LL di=dp[i]+sz[i]*(dep[i]-dep[p]);
        ans+=dp[p]*sz[i]+di*sz[p];
        sz[p]+=sz[i];
        dp[p]+=di;
    }
}

void solve() {
    while ( m-- ) {
        int qn;
        R(qn);
        VI q;
        q.resize(qn);
        REP(i,qn) R(q[i]);
        int rt=build_t(q);
        ans=0;
        for ( int i:q ) inq[i]=1;
        go(rt);
        for ( int i:q ) inq[i]=0;
        W(2*ans);
    }
}

int main() {
    int t;
    R(t);
    while ( t-- ) {
        input();
        build();
        solve();
    }
    return 0;
}
