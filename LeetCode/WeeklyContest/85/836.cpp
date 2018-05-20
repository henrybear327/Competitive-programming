#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
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
// range of input?
class Solution
{
private:
    struct Point {
        int x, y;
    };

    bool doOverlap(Point l1, Point r1, Point l2, Point r2)
    {
        // 在他的左邊 or 右邊
        if (r1.x <= l2.x || r2.x <= l1.x)
            return false;

        // 在他的上面 or 下面
        if (r2.y <= l1.y || r1.y <= l2.y)
            return false;

        return true;
    }

public:
    bool isRectangleOverlap(vector<int> &rec1,
                            vector<int> &rec2) // [x1, y1, x2, y2]
    {
        Point l1{rec1[0], rec1[1]};
        Point r1{rec1[2], rec1[3]};
        Point l2{rec2[0], rec2[1]};
        Point r2{rec2[2], rec2[3]};
        return doOverlap(l1, r1, l2, r2) || doOverlap(l2, r2, l1, r1);
    }
};

#ifdef LOCAL
int main()
{
    return 0;
}
#endif