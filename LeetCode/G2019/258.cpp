class Solution
{
private:
    int ok(int n)
    {
        int s = 0;
        while (n > 0) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

public:
    // 38 11 2
    int addDigits(int num)
    {
        while (ok(num) >= 10) {
            num = ok(num);
        }
        return ok(num);
    }
};
