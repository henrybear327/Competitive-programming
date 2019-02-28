class Solution
{
private:
    int toInt(char c)
    {
        return c - '0';
    }

    string toTime(int minute)
    {
        int hh = minute / 60;
        string hhs = (hh < 10 ? "0" : "") + to_string(hh);
        int mm = minute % 60;
        string mms = (mm < 10 ? "0" : "") + to_string(mm);

        return hhs + ":" + mms;
    }

public:
    string nextClosestTime(string time)
    {
        const int orig = (toInt(time[0]) * 10 + toInt(time[1])) * 60 +
                         (toInt(time[3]) * 10 + toInt(time[4]));
        string ans;
        int diff = INT_MAX;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                for (int k = 0; k < 5; k++)
                    for (int l = 0; l < 5; l++) {
                        if (i == 2 || j == 2 || k == 2 || l == 2)
                            continue;
                        int minute = (toInt(time[i]) * 10 + toInt(time[j])) * 60 +
                                     (toInt(time[k]) * 10 + toInt(time[l]));

                        if ((toInt(time[i]) * 10 + toInt(time[j])) >= 24 ||
                            (toInt(time[k]) * 10 + toInt(time[l]) >= 60))
                            continue;

                        if (minute == orig)
                            continue;

                        int curDiff = minute - orig;
                        curDiff = curDiff < 0 ? curDiff + 24 * 60 : curDiff;

                        if (curDiff < diff) {
                            diff = curDiff;
                            ans = toTime(minute);
                        }
                    }

        return ans == "" ? time : ans;
    }
};

// class Solution {
// private:
//     int toInt(char c)
//     {
//         return c - '0';
//     }

//     int toMinute(string time)
//     {
//         // 12:34
//         return (toInt(time[0]) * 10 + toInt(time[1])) * 60 + (toInt(time[3])
//         * 10 + toInt(time[4]));
//     }

//     string toTime(int minute)
//     {
//         int hh = minute / 60;
//         string hhs = (hh < 10 ? "0" : "") + to_string(hh);
//         int mm = minute % 60;
//         string mms = (mm < 10 ? "0" : "") + to_string(mm);

//         return hhs + ":" + mms;
//     }

//     bool check(string orig, string time)
//     {
//         for(auto i : time) {
//             bool ok = false;
//             for(auto j : orig) {
//                 if(i == j) {
//                     ok = true;
//                     break;
//                 }
//             }

//             if(ok)
//                 continue;
//             return false;
//         }
//         return true;
//     }

// public:
//     // one special case: all digits are the same......
//     string nextClosestTime(string time) {
//         int origMinute = toMinute(time);

//         int diff = INT_MAX;
//         string ans;
//         for(int i = 0; i < 24*60; i++) {
//             string ret = toTime(i);
//             if(time != ret && check(time, ret)) { // mind the first
//             condition!
//                 // cout << ret << endl;
//                 int tmp = i - origMinute;
//                 tmp = tmp > 0 ? tmp : tmp + 24*60;
//                 // cout << tmp << " = " << i << " - " << origMinute << endl;
//                 // cout << diff << endl;

//                 if(tmp < diff) {
//                     ans = ret;
//                     diff = tmp; // lol
//                 }
//             }
//         }

//         return ans == "" ? time : ans;
//     }
// };
