#include <algorithm>
#include <array>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

template <class T, size_t... I>
void print_tuple(ostream &s, T const &a, index_sequence<I...>)
{
    using swallow = int[];
    (void)swallow{0, (void(s << (I == 0 ? "" : ", ") << get<I>(a)), 0)...};
}

template <class T> ostream &print_collection(ostream &s, T const &a);
template <class... A> ostream &operator<<(ostream &s, tuple<A...> const &a);
template <class A, class B>
ostream &operator<<(ostream &s, pair<A, B> const &a);

template <class T, size_t I>
ostream &operator<<(ostream &s, array<T, I> const &a)
{
    return print_collection(s, a);
}
template <class T> ostream &operator<<(ostream &s, vector<T> const &a)
{
    return print_collection(s, a);
}
template <class T> ostream &operator<<(ostream &s, deque<T> const &a)
{
    return print_collection(s, a);
}
template <class T, class U>
ostream &operator<<(ostream &s, multimap<T, U> const &a)
{
    return print_collection(s, a);
}
template <class T> ostream &operator<<(ostream &s, multiset<T> const &a)
{
    return print_collection(s, a);
}
template <class T, class U>
ostream &operator<<(ostream &s, map<T, U> const &a)
{
    return print_collection(s, a);
}
template <class T> ostream &operator<<(ostream &s, set<T> const &a)
{
    return print_collection(s, a);
}

template <class T> ostream &print_collection(ostream &s, T const &a)
{
    s << '[';
    for (auto it = begin(a); it != end(a); ++it) {
        s << *it;
        if (it != prev(end(a)))
            s << " ";
    }
    return s << ']';
}

template <class... A> ostream &operator<<(ostream &s, tuple<A...> const &a)
{
    s << '(';
    print_tuple(s, a, index_sequence_for<A...> {});
    return s << ')';
}

template <class A, class B>
ostream &operator<<(ostream &s, pair<A, B> const &a)
{
    return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}

using li = long long int;
using lu = long long unsigned;
using ld = long double;

using pii = tuple<li, li>;
using piii = tuple<li, li, li>;
using piiii = tuple<li, li, li, li>;
using vi = vector<li>;
using vii = vector<pii>;
using viii = vector<piii>;
using vvi = vector<vi>;
using vvii = vector<vii>;
using vviii = vector<viii>;

template <class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T> using max_queue = priority_queue<T>;

struct empty_t {};

namespace tuple_access
{

struct xx_t {
} xx;
struct yy_t {
} yy;
struct zz_t {
} zz;
struct ww_t {
} ww;

template <class T> typename tuple_element<0, T>::type &operator^(T &v, xx_t)
{
    return get<0>(v);
}
template <class T>
typename tuple_element<0, T>::type const &operator^(T const &v, xx_t)
{
    return get<0>(v);
}
template <class T> typename tuple_element<0, T>::type &&operator^(T &&v, xx_t)
{
    return get<0>(v);
}

template <class T> typename tuple_element<1, T>::type &operator^(T &v, yy_t)
{
    return get<1>(v);
}
template <class T>
typename tuple_element<1, T>::type const &operator^(T const &v, yy_t)
{
    return get<1>(v);
}
template <class T> typename tuple_element<1, T>::type &&operator^(T &&v, yy_t)
{
    return get<1>(v);
}

template <class T> typename tuple_element<2, T>::type &operator^(T &v, zz_t)
{
    return get<2>(v);
}
template <class T>
typename tuple_element<2, T>::type const &operator^(T const &v, zz_t)
{
    return get<2>(v);
}
template <class T> typename tuple_element<2, T>::type &&operator^(T &&v, zz_t)
{
    return get<2>(v);
}

template <class T> typename tuple_element<3, T>::type &operator^(T &v, ww_t)
{
    return get<3>(v);
}
template <class T>
typename tuple_element<3, T>::type const &operator^(T const &v, ww_t)
{
    return get<3>(v);
}
template <class T> typename tuple_element<3, T>::type &&operator^(T &&v, ww_t)
{
    return get<3>(v);
}
} // namespace tuple_access
using namespace tuple_access;

int ilog2(int x)
{
    return 31 - __builtin_clz(x);
}

template <class T> struct identity : std::unary_function<T, T> {
    T operator()(const T &x) const
    {
        return x;
    }
};

template <class T> T &smin(T &x, T const &y)
{
    x = min(x, y);
    return x;
}

template <class T> T &smax(T &x, T const &y)
{
    x = max(x, y);
    return x;
}

template <typename T> T isqrt(T const &x)
{
    static_assert(is_integral<T>::value, "is_integral<T>::value");
    assert(x >= T(0));
    T ret = static_cast<T>(sqrtl(x));
    while (ret > 0 && ret * ret > x)
        --ret;
    while (x - ret * ret > 2 * ret)
        ++ret;
    return ret;
}

template <typename T> T icbrt(T const &x)
{
    static_assert(is_integral<T>::value, "is_integral<T>::value");
    assert(x >= T(0));
    T ret = static_cast<T>(cbrt(x));
    while (ret > 0 && ret * ret * ret > x)
        --ret;
    while (x - ret * ret * ret > 3 * ret * (ret + 1))
        ++ret;
    return ret;
}

pii mkP(li a, li b)
{
    li g = __gcd(a, b);
    a /= g;
    b /= g;
    return make_tuple(a, b);
}

bool cmpPii(pii const &a, pii const &b)
{
    li x1, y1;
    tie(x1, y1) = a;
    li x2, y2;
    tie(x2, y2) = b;
    return (x1 * y2) < (x2 * y1);
}

void solve()
{
    li n, d;
    cin >> n >> d;
    vi A(n);
    for (li i = 0; i < (li)(n); ++i)
        cin >> A[i];
    sort(begin(A), end(A));
    li ans = d;

    set<pii> S;
    for (li i = 0; i < (li)(n); ++i) {
        for (li x = (1); x <= (li)(d); ++x) {
            S.insert(mkP(A[i], x));
        }
    }

    vii B(begin(S), end(S));
    sort(begin(B), end(B), cmpPii);
    vector<deque<li>> C(d + 1);
    for (li i = 0; i < (li)(n); ++i)
        C[d].push_back(A[i]);

    for (auto const &ab : B) {
        li a, b;
        tie(a, b) = ab;
        vi cntPerfect(d + 1);
        for (li x = (d); x >= (li)(1); --x) {
            while (!C[x].empty() && b * C[x].front() <= x * a) {
                if (b * C[x].front() == x * a)
                    cntPerfect[x] += 1;
                else
                    C[x - 1].push_back(C[x].front());
                C[x].pop_front();
            }
        }

        vi dp(d + 1, 1e9);
        dp[0] = 0;
        for (li x = (d); x >= (li)(1); --x)
            for (li y = 0; y < (li)(cntPerfect[x]); ++y) {
                for (li z = (d - x); z >= (li)(0); --z)
                    dp[z + x] = min(dp[z + x], dp[z] + (x - 1));
            }
        li cntBonus = 0;
        for (li x = (d); x >= (li)(1); --x)
            cntBonus += x * C[x].size();
        for (li i = 0; i < (li)(1 + min(d, cntBonus)); ++i)
            ans = min(ans, dp[d - i] + i);

        for (li x = (d); x >= (li)(1); --x)
            for (li y = 0; y < (li)(cntPerfect[x]); ++y) {
                C[x - 1].push_back((x * a) / b);
            }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (li i = 0; i < (li)(t); ++i) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}
