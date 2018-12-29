#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

vector<ii> inp;

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    return a == 0 ? b : gcd(b % a, a);
}

struct Fraction { // numerator / denominator
    Fraction() {}
    Fraction(ll numerator, ll denominator)
    {
        ll g = gcd(numerator, denominator);

        this->numerator = numerator / g;
        this->denominator = denominator / g;

        if (this->denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }
    }

    Fraction(ll a)
    {
        this->numerator = a;
        this->denominator = 1;
    }

    Fraction operator+(const Fraction &other)
    {
        ll a = this->numerator;
        ll b = this->denominator;
        ll c = other.numerator;
        ll d = other.denominator;

        return Fraction(a * d + b * c, b * d);
    }

    Fraction operator*(const Fraction &other)
    {
        ll a = this->numerator;
        ll b = this->denominator;
        ll c = other.numerator;
        ll d = other.denominator;

        return Fraction(a * c, b * d);
    }

    bool operator==(const Fraction &other)
    {
        return (this->numerator == other.numerator) &&
               (this->denominator == other.denominator);
    }

    void print()
    {
        printf("%lld / %lld\n", numerator, denominator);
    }

    ll numerator;
    ll denominator;
};

struct Line {
    Line() {}
    Line(Fraction a, Fraction b)
    {
        this->a = a;
        this->b = b;
    }

    void print()
    {
        printf("y = %lld / %lld x + %lld / %lld\n", a.numerator, a.denominator,
               b.numerator, b.denominator);
    }

    Fraction a, b;
};

Line make_line(int i, int j)
{
    // y = ax + b
    ll dx = inp[j].first - inp[i].first;
    ll dy = inp[j].second - inp[i].second;
    Fraction slope(dy, dx);

    ll x = inp[i].first;
    ll y = inp[i].second;
    Fraction b(y * slope.denominator - slope.numerator * x, slope.denominator);

    return Line(slope, b);
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        ii tmp;
        tmp.first = i + 1;
        scanf("%lld", &tmp.second);

        inp.push_back(tmp);
    }

    bool ok = false;
    {
        for (int i = 1; i < n; i++) {
            Line line = make_line(0, i);
            // line.print();

            bool onLine[n];
            memset(onLine, 0, sizeof(onLine));

            int cnt = 0;
            for (int j = 0; j < n; j++) {
                ll &x = inp[j].first;
                ll &y = inp[j].second;

                // printf("x %lld y %lld\n", x, y);
                Fraction res = line.a * x + line.b;
                // res.print();

                if (res == y) {
                    // printf("%d is online\n", j);
                    onLine[j] = true;
                    cnt++;
                }
            }
            // printf("\n\n");

            if (cnt == n)
                continue;
            if (cnt == n - 1) {
                ok = true;
                break;
            }

            int cnt1 = 0;
            Line line1;
            if (cnt >= 2) {
                vector<int> cand;
                for (int j = 0; j < n; j++) {
                    if (onLine[j] == false)
                        cand.push_back(j);
                }

                line1 = make_line(cand[0], cand[1]);
                for (int j = 0; j < n; j++) {
                    ll &x = inp[j].first;
                    ll &y = inp[j].second;

                    // printf("x %lld y %lld\n", x, y);
                    Fraction res = line1.a * x + line1.b;
                    // res.print();

                    if (res == y) {
                        // printf("%d is online\n", j);
                        onLine[j] = true;
                        cnt1++;
                    }
                }
                // printf("\n\n");
            }

            if ((cnt + cnt1) == n && line.a == line1.a) {
                ok = true;
                break;
            }
        }
    }

    if (ok)
        printf("Yes\n");
    else {
        Line line = make_line(1, 2);
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            ll &x = inp[j].first;
            ll &y = inp[j].second;

            // printf("x %lld y %lld\n", x, y);
            Fraction res = line.a * x + line.b;
            // res.print();

            if (res == y) {
                // printf("%d is online\n", j);
                cnt++;
            }
        }
        // printf("\n\n");

        if (cnt == n - 1)
            ok = true;
        if (ok)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
