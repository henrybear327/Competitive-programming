#include <cstdio>

int main()
{
    int size, total;
    while (scanf("%d %d", &size, &total) == 2 && (size || total)) {
        int x = (size + 1) / 2, y = (size + 1) / 2;

        int step = 1, vertical = 1, horizontal = 1;
        int delta_v = 0, delta_h = 0;
        bool is_vertical = true, v_up = true, h_right = false;
        while (1) {
            if (is_vertical && step + vertical < total) {
                step += vertical;
                is_vertical = !is_vertical;

                delta_v += (v_up ? vertical : -1 * vertical);
                vertical++;
                v_up = !v_up;
            } else if (!is_vertical && step + horizontal < total) {
                step += horizontal;
                is_vertical = !is_vertical;

                delta_h += (h_right ? horizontal : -1 * horizontal);
                horizontal++;
                h_right = !h_right;
            } else {
                if (is_vertical) {
                    int tmp = total - step;
                    delta_v += (v_up ? tmp : -1 * tmp);
                } else {
                    int tmp = total - step;
                    delta_h += (h_right ? tmp : -1 * tmp);
                }
                break;
            }
        }

        printf("Line = %d, column = %d.\n", y + delta_v, x + delta_h);
    }

    return 0;
}
