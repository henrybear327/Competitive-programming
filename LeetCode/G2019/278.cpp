// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        // vvvxxx
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isBadVersion(mid))
                r = mid - 1; // x
            else
                l = mid + 1; // v
        }

        return l;
    }
};
