class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        sort(points.begin(), points.end(),
        [](const vector<int> &a, const vector<int> &b) {
            int da = a[0] * a[0] + a[1] * a[1];
            int db = b[0] * b[0] + b[1] * b[1];

            return da < db;
        });

        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
