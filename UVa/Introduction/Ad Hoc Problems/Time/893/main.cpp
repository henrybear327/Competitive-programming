#include <cstdio>

const int month_day[13] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int year)
{
    /*Leap years are all years divisible by 4 and not divisible by 100, except
    for those divisible by 400*/

    /*
        if (year % 4 == 0 &&
            (year % 100 != 0 || (year % 100 == 0 && year % 400 == 0)))
            return true;
        return false;
    */
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int main()
{
    int add, dd, mm, yyyy;
    while (scanf("%d %d %d %d", &add, &dd, &mm, &yyyy) == 4 &&
           (add || dd || mm || yyyy)) {
        while (add) {
            // get the year first, then do month and day
            /*
            if (add >= 366 && is_leap(yyyy) == true &&
                mm <= 2) { // if the leap year is after February, then there will be
                // no effect!
                yyyy++;
                add -= 366;
            } else if (add >= 365 && is_leap(yyyy) == false) {
                yyyy++;
                add -= 365;
            }*/
            if (add >= 365) {
                if (is_leap(yyyy) && mm <= 2)
                    add -= 366;
                else if (mm > 2 && is_leap(yyyy + 1))
                    add -= 366;
                else
                    add -= 365;

                yyyy++;
            } else {
                if (add + dd >
                    month_day[mm == 2 ? (is_leap(yyyy) == true ? 0 : 2) : mm]) {
                    add = dd + add -
                          month_day[mm == 2 ? (is_leap(yyyy) == true ? 0 : 2) : mm] - 1;
                    dd = 1;
                    mm++;
                } else {
                    dd = dd + add;
                    add = 0;
                }

                if (mm == 13) {
                    yyyy++;
                    mm = 1;
                }
            }
        }

        printf("%d %d %d\n", dd, mm, yyyy);
    }

    return 0;
}
