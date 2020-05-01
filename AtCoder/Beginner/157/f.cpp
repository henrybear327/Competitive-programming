#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const double EPS = 1e-6;
const int LOOPCOUNT = 100;

struct Data {
    double x, y, c;
};

double dist2(Data a, Data b)
{
    double dx = b.x - a.x;
    double dy = b.y - a.y;

    return dx * dx + dy * dy;
}

void cal(Data candidates[], Data a, Data b, double r1, double r2)
{
    double d = sqrt(dist2(a, b));
    double l = (r1 * r1 - r2 * r2 + d * d) / (2.0 * d);
    if (r1 * r1 - l * l < 0) {
        /*
        candidates[0] = a;
        candidates[1] = b;
        return;
        */
    }
    double h = r1 * r1 - l * l;
    /*    if (abs(h) < EPS)
            h = 0.0;
        else if (h < 0.0) {
            candidates[0] = a;
            candidates[1] = b;
            return;
        }
    */
    h = sqrt(h);

    candidates[0].x = (l / d) * (b.x - a.x) + (h / d) * (b.y - a.y) + a.x;
    candidates[0].y = (l / d) * (b.y - a.y) - (h / d) * (b.x - a.x) + a.y;
    candidates[1].x = (l / d) * (b.x - a.x) - (h / d) * (b.y - a.y) + a.x;
    candidates[1].y = (l / d) * (b.y - a.y) + (h / d) * (b.x - a.x) + a.y;
}

bool check(int n, Data inp[], int kkk, double t)
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double r1 = t / inp[i].c;
            double r2 = t / inp[j].c;

            // printf("t %f r1 %f r2 %f\n", t, r1, r2);

            double X = max(r1, r2) - min(r1, r2);
            X *= X;
            double Y = r1 + r2;
            Y *= Y;

            // get intersection points (2)
            Data candidates[4];
            candidates[3] = inp[i];
            candidates[2] = inp[j];
            double dist = dist2(inp[i], inp[j]);
            if (X - dist > -EPS) {
                // case 1
                candidates[0] = inp[i];
                candidates[1] = inp[j];
            } else if (fabs(X - dist) < EPS || fabs(Y - dist) < EPS) {
                // case 2
                cal(candidates, inp[i], inp[j], r1, r2);
            } else if (dist - Y > -EPS) {
                // case 4, no
                candidates[0] = inp[i];
                candidates[1] = inp[j];
            } else {
                // case 3
                cal(candidates, inp[i], inp[j], r1, r2);
            }

            // printf("%d %d, (%f %f) (%f %f)\n", i, j, candidates[0].x,
            // candidates[0].y,
            //     candidates[1].x, candidates[1].y);

            // see if we have more than k hits
            for (int k = 0; k < 4; k++) {
                int cnt = 0;
                for (int x = 0; x < n; x++) {
                    dist = sqrt(dist2(candidates[k], inp[x]) * inp[x].c * inp[x].c);
                    if (t - dist > -EPS) // t >= dist
                        cnt++;
                }

                if (cnt >= kkk) {
                    //    printf("%.15f, %d\n", t, cnt);
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    Data inp[n];
    for (int i = 0; i < n; i++)
        scanf("%lf %lf %lf", &inp[i].x, &inp[i].y, &inp[i].c);

    if (n == 1) {
        printf("0.0000000000\n");
        return 0;
    }

    double l = 0, r = 1e9;
    for (int i = 0; i < LOOPCOUNT; i++) {
        double mid = (l + r) / 2;
        // printf("fuck %f %f %f\n", l, mid, r);
        if (check(n, inp, k, mid))
            r = mid;
        else
            l = mid;
    }

    printf("%.15f\n", r);

    return 0;
}
