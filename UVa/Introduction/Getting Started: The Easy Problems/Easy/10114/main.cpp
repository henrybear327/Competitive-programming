#include <cstdio>

int main()
{
    int duration, record;
    double down, amount;

    while (scanf("%d %lf %lf %d", &duration, &down, &amount, &record) == 4 &&
           duration > 0) {
        bool flag = true;
        int month;
        double prev_rate, monthly_payment = amount / duration;
        scanf("%d %lf", &month, &prev_rate);
        record--;

        double car_value = (amount + down) * (1 - prev_rate);

        // printf("0 %f %f\n", car_value, amount);

        if (car_value > amount) {
            printf("0 months\n");
            flag = false;
        }

        int curr_month = 1;
        double rate = prev_rate;
        for (int i = 0; i < record; i++) {
            scanf("%d %lf", &month, &rate);
            while (flag && curr_month < month) {
                car_value *= (1 - prev_rate);
                amount -= monthly_payment;

                // printf("1 %f %f\n", car_value, amount);

                if (car_value > amount) {
                    if (curr_month == 1) {
                        printf("1 month\n");
                    } else
                        printf("%d months\n", curr_month);
                    flag = false;
                    break;
                }
                curr_month++;
            }
            prev_rate = rate;
        }

        if (flag) {
            while (flag && curr_month <= duration) {
                car_value *= (1 - rate);
                amount -= monthly_payment;

                // printf("2 %f %f\n", car_value, amount);

                if (car_value > amount) {
                    printf("%d months\n", curr_month);
                    flag = false;
                    break;
                }
                curr_month++;
            }
        }
    }
    return 0;
}
