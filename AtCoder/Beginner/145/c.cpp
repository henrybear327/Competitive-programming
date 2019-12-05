#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> seq;
    for (int i = 0; i < n; i++)
        seq.push_back(i);

    vector<ii> pt;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        pt.push_back({x, y});
    }

    int total = 0;
    double sum = 0;
    do {
        total++;
        double tmp = 0;
        for (int i = 1; i < n; i++) {
            int dx = pt[seq[i]].first - pt[seq[i - 1]].first;
            int dy = pt[seq[i]].second - pt[seq[i - 1]].second;
            tmp += sqrt(1.0 * dx * dx + 1.0 * dy * dy);
        }
        sum += tmp;
    } while (next_permutation(seq.begin(), seq.end()));

    printf("%.15f\n", 1.0 * sum / total);

    return 0;
}
