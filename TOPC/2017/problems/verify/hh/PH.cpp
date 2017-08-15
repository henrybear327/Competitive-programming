//bcw0x1bd2 {{{
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define FZ(x) memset((x),0,sizeof(x))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define SZ(x) ((int)((x).size()))
#define ALL(x) begin(x),end(x)
#define REP(i,x) for (int i=0; i<(x); i++)
#define REP1(i,a,b) for (int i=(a); i<=(b); i++)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

#ifdef DARKHH
#define FILEIO(name)
#else
#define FILEIO(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#endif

#ifdef DARKHH
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
// }}}
// Let's Fight! ~OAO~~

const int MAXN = 100005;
#include <sys/resource.h>
void increase_stack_size() {
  const rlim_t ks = 64*1024*1024;
  struct rlimit rl;
  int res=getrlimit(RLIMIT_STACK, &rl);
  if(res==0){
    if(rl.rlim_cur<ks){
      rl.rlim_cur=ks;
      res=setrlimit(RLIMIT_STACK, &rl);
    }
  }
}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef gp_hash_table<int,ll> umap_t;

struct QQ {
  umap_t cnt, sum;

  void init() {
    cnt.clear();
    sum.clear();
  }

  ll qcnt(int qid) { return cnt[qid]; }
  ll qsum(int qid) { return sum[qid]; }
  int size() { return SZ(cnt); }

  void add(int qid, ll c, ll v) {
    cnt[qid] += c;
    sum[qid] += v;
  }

  vector<int> get_qid() {
    vector<int> res;
    for (auto it: cnt) res.PB(it.F);
    return res;
  }

} zz[MAXN];

int N,Q,dep[MAXN],zid[MAXN];
vector<int> E[MAXN],tag[MAXN];
ll ans[MAXN];
int counter = 0;

void merge(int a, int b, ll d) {
  vector<int> vec = zz[b].get_qid();
  for (auto qid: vec) {
    assert(1 <= qid and qid <= Q);
    int cnt = zz[b].qcnt(qid);
    ll c = zz[a].qcnt(qid);
    ans[qid] += zz[b].qsum(qid) * c;
    ans[qid] += zz[a].qsum(qid) * cnt;
    ans[qid] -= 2 * d * c * cnt;
    counter++;
  }
  for (auto qid: vec) {
    zz[a].add(qid, zz[b].qcnt(qid), zz[b].qsum(qid));
    counter++;
  }
}
void DFS(int u, int d) {
  dep[u] = d;
  for (auto it: tag[u]) {
    zz[u].add(it, 1, d);
  }

  int &id = zid[u];
  int bv = u;
  int maxSz = zz[u].size();

  for (auto v:E[u]) {
    E[v].erase(find(ALL(E[v]), u));
    DFS(v, d+1);
    int vid = zid[v];
    if (zz[vid].size() > maxSz) {
      maxSz = zz[vid].size();
      bv = v;
      id = vid;
    }
  }

  for (auto v:E[u]) {
    if (v == bv) continue;
    merge(id, zid[v], dep[u]);
  }

  if (id != u) merge(id, u, dep[u]);
}

int main() {
  IOS;
  increase_stack_size();
  int nT;
  cin>>nT;
  assert(nT <= 100);
  REP1(cas,1,nT) {
    cin>>N>>Q;
    assert(2 <= N and N <= 100000);
    assert(1 <= Q and Q <= 100000);
    dump(cas,N,Q);

    REP1(i,0,N) {
      E[i].clear();
      tag[i].clear();
      dep[i] = 0;
      zz[i].init();
      zid[i] = i;
    }
    REP1(i,0,Q) {
      ans[i] = 0;
    }
    REP(i,N-1) {
      int u,v;
      cin>>u>>v;
      assert(1 <= u and u <= N);
      assert(1 <= v and v <= N);
      E[u].PB(v);
      E[v].PB(u);
    }

    int totk = 0;

    REP1(i,1,Q) {
      int k;
      cin>>k;
      assert(2 <= k and k <= N);
      totk += k;
      REP(j,k) {
        int qid;
        cin>>qid;
        assert(1 <= qid and qid <= N);
        tag[qid].PB(i);
      }
    }

    assert(totk <= 200000);

    DFS(1,1);
    REP1(i,1,N) assert(dep[i] != 0);
    REP1(i,1,Q) {
      ans[i] *= 2;
      cout<<ans[i]<<"\n";
    }

  }
  dump(counter);

  return 0;
}

