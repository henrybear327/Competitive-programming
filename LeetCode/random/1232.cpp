class Solution
{
    /*
    [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
    [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
    [[-3,-2],[-1,-2],[2,-2],[-2,-2],[0,-2]]
    */
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int n = coordinates.size();

        for (int i = 2; i < n; i++) {
            int x[3] = {coordinates[i - 2][0], coordinates[i - 1][0],
                        coordinates[i][0]
                       };
            int y[3] = {coordinates[i - 2][1], coordinates[i - 1][1],
                        coordinates[i][1]
                       };

            int left = (y[1] - y[0]) * (x[2] - x[1]);
            int right = (y[2] - y[1]) * (x[1] - x[0]);

            if (left != right)
                return false;
        }

        return true;

        //         sort(coordinates.begin(), coordinates.end());

        //         for(int i = 2; i < n; i++) {
        //             int dx = coordinates[i][0] - coordinates[i - 1][0];
        //             int dy = coordinates[i][1] - coordinates[i - 1][1];
        //             int g = __gcd(dx, dy);
        //             dx /= g;
        //             dy /= g;

        //             int dxx = coordinates[i - 1][0] - coordinates[i - 2][0];
        //             int dyy = coordinates[i - 1][1] - coordinates[i - 2][1];
        //             int gg = __gcd(dxx, dyy);
        //             dxx /= gg;
        //             dyy /= gg;

        //             // cout << dx << " " << dy << endl;
        //             // cout << dxx << " " << dyy << endl;

        //             // vertical
        //             if(dx == 0 && dxx == 0)
        //                 continue;
        //             // horizontal
        //             if(dy == 0 && dyy == 0)
        //                 continue;

        //             if(dx != dxx || dy != dyy)
        //                 return false;
        //         }

        //         return true;
    }
};
