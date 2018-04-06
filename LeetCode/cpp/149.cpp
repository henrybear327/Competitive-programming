#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
#endif

static int __initialSetup = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
();

// handle special cases first
// [], "", ...
class Solution
{
private:
    int gcd(int a, int b)
    {
        a = abs(a);
        b = abs(b);
        return a == 0 ? b : gcd(b % a, a);
    }

public:
    // O(n^2)
    int maxPoints(vector<Point> &points)
    {
        int n = (int)points.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> slope;
            int special = 0;
            for (int j = 0; j < n; j++) {
                Point &a = points[i];
                Point &b = points[j];

                int dx = a.x - b.x;
                int dy = a.y - b.y;
                int g = gcd(dx, dy);
                if (dx == 0 && dy == 0) { // case: point duplicate, WTF
                    special++;
                    continue;
                }
                dx /= g;
                dy /= g;

                slope[make_pair(dx, dy)]++;
            }

            int cnt = 0;
            for (auto j : slope) {
                cnt = max(cnt, j.second);
            }
            ans = max(ans, special + cnt);
        }
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif