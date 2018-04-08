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
    inline void cal(int &fh, int &fm, int &ch, int &cm, int &dh, int &dm)
    {
        if (cm > fm) {
            fh--;
            fm += 60;
        }
        dm = fm - cm;
        dh = fh - ch;
    }

    inline bool valid(int h, int m)
    {
        return h >= 0 && h <= 23 && m >= 0 && m <= 59;
    }

    inline void split(string s, int &h, int &m)
    {
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == ':') {
                h = stoi(s.substr(0, i));
                m = stoi(s.substr(i + 1));
                break;
            }
        }
    }

    // a way better way will be ...
    // convert to minute, compare, and convert back...
    inline int diffInTime(string current, string future)
    {
        // future - current
        int ch = -1, cm = -1;
        split(current, ch, cm);
        // assert(ch != -1 && cm != -1);

        int fh = -1, fm = -1;
        split(future, fh, fm);
        // assert(fh != -1 && fm != -1);

        int dh = -1, dm = -1;
        if (fh > ch || (fh == ch && fm >= cm)) { // 4:10 - 3:59
            cal(fh, fm, ch, cm, dh, dm);
        } else { // 21:00 - 22:00 = 23 hour = 24 - 1 hour
            swap(ch, fh);
            swap(cm, fm);

            cal(fh, fm, ch, cm, dh, dm);
            fh = 24;
            fm = 0;
            ch = dh;
            cm = dm;
            cal(fh, fm, ch, cm, dh, dm);
        }

        return dh * 60 + dm;
    }

public:
    string nextClosestTime(string time)
    {
        // cout << diffInTime("00:00", "03:00") << endl;
        // cout << diffInTime("00:00", "12:00") << endl;
        // cout << diffInTime("12:00", "00:00") << endl;
        // cout << diffInTime("12:00", "11:00") << endl;
        // cout << diffInTime("00:00", "00:00") << endl;
        // cout << "--------" << endl;
        // cout << diffInTime("12:30", "13:00") << endl;
        // cout << diffInTime("13:00", "12:59") << endl;
        // cout << diffInTime("00:00", "00:00") << endl;
        // cout << diffInTime("00:00", "00:00") << endl;
        int hour = -1, minute = -1;
        split(time, hour, minute);
        int nums[4];
        nums[0] = hour / 10 % 10;
        nums[1] = hour % 10;
        nums[2] = minute / 10 % 10;
        nums[3] = minute % 10;

        int diff = INT_MAX;
        string who = "";
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    for (int l = 0; l < 4; l++) {
                        int hh = nums[i] * 10 + nums[j];
                        int mm = nums[k] * 10 + nums[l];
                        if (valid(hh, mm) == false)
                            continue;

                        string tmp = (hh < 10 ? "0" : "") + to_string(hh) + ":" +
                                     (mm < 10 ? "0" : "") + to_string(mm);
                        auto cache = diffInTime(time, tmp);
                        if (tmp != time && diff > cache) {
                            diff = cache;
                            who = tmp;
                        }
                    }
                }
            }
        }
        return who == "" ? time : who;
    }
};

#ifdef LOCAL
int main()
{
    cout << Solution().nextClosestTime("00:00") << endl;
    cout << Solution().nextClosestTime("19:34") << endl;
    cout << Solution().nextClosestTime("23:59") << endl;
    return 0;
}
#endif