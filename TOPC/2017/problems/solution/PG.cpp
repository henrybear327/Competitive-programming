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
const int MAX = 2147483647;
using BS = bitset<5>;

struct Trie {
  static const int S = 31;
  static const int MEM = S * MAXN + 5;
  struct Node {
    int tot,lv,ch[2],cnt[S];
    Node () {
      tot = lv = ch[0] = ch[1] = 0;
      memset(cnt, 0, sizeof(cnt));
    }
  };

  Node tree[MEM];
  int root, xmask, mem;

  void init() {
    xmask = 0;
    mem = 1;
    root = get_node();
    tree[root].lv = S-1;
  }
  void rox(int x) {
    xmask ^= x;
  }
  int get_node() {
    assert(mem < MEM);
    tree[mem] = Node();
    return mem++;
  }
  void add(int x) {
    x ^= xmask;
    //dump(BS(x));
    static vector<int> vec;
    vec.clear();
    int id = root;
    for (int i=S-1; i>=0; i--) {
      int b = (x >> i) & 1;
      auto &ch = tree[id].ch[b];
      if (ch == 0) ch = get_node();
      vec.PB(id);
      tree[ch].lv = i-1;
      id = ch;
    }
    vec.PB(id);
    for (auto i: vec) {
      tree[i].tot++;
      REP(j,S) {
        if ((x>>j)&1) tree[i].cnt[j]++;
      }
    }
  }
  ll qry(int k) {
    int res[S];
    memset(res, 0, sizeof(res));
    //dump(k, BS(xmask));
    int id = root;
    while (id) {
      if (tree[id].lv == -1 or tree[id].tot <= k) {
        REP(i,S) {
          if ((xmask>>i)&1) res[i] += min(tree[id].tot - tree[id].cnt[i], k);
          else res[i] += min(tree[id].cnt[i], k);
        }
        break;
      }
      int lc = tree[id].ch[0 ^ ((xmask>>tree[id].lv)&1)];
      int rc = tree[id].ch[1 ^ ((xmask>>tree[id].lv)&1)];
      if (tree[lc].tot >= k) id = lc;
      else {
        REP(i,S) {
          if ((xmask>>i)&1) res[i] += tree[lc].tot - tree[lc].cnt[i];
          else res[i] += tree[lc].cnt[i];
        }
        id = rc;
        k -= tree[lc].tot;
      }
    }
    ll r = 0;
    REP(i,S) {
      //if (i < 5) dump(i, res[i]);
      r += (1LL << i) * res[i];
    }
    return r;
  }
} trie;

int N,Q;
int ip[MAXN];

int main() {
  IOS;
  int nT;
  cin>>nT;
  int big = 0;
  REP1(cas,1,nT) {
    dump(cas);
    cin>>N>>Q;
    if (N + Q > 200) big++;
    assert(1 <= N and N <= 100000);
    assert(1 <= Q and Q <= 100000);
    trie.init();
    REP(i,N) {
      cin>>ip[i];
      assert(0 <= ip[i] and ip[i] <= MAX);
      trie.add(ip[i]);
    }
    REP(_,Q) {
      int cmd,x;
      cin>>cmd>>x;
      assert(cmd == 1 or cmd == 2);
      if (cmd == 1) {
        assert(0 <= x and x <= MAX);
        trie.rox(x);
      } else {
        assert(1 <= x and x <= N);
        ll res = trie.qry(x);
        cout<<res<<"\n";
      }
    }
  }
  assert(big <= 5);

  return 0;
}

