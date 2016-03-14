#include <iostream>
using namespace std;
int a[20][20];
int tt;
int you(int i, int j, int stone)
{
    if (i < 0 || i > 19 || j < 0 && j > 19)
        return 0;
    if (a[i][j] == stone) {
        tt++;
        you(i, j + 1, stone);
    }
    return 0;
}

int xia(int i, int j, int stone)
{
    if (i < 0 || i > 19 || j < 0 && j > 19)
        return 0;
    if (a[i][j] == stone) {
        tt++;
        xia(i + 1, j, stone);
    }
    return 0;
}
int xiayou(int i, int j, int stone)
{
    if (i < 0 || i > 19 || j < 0 && j > 19)
        return 0;
    if (a[i][j] == stone) {
        tt = tt + 1;
        xiayou(i + 1, j + 1, stone);
    }
    return 0;
}
int xiazuo(int i, int j, int stone)
{
    if (i < 0 || i > 19 || j < 0 && j > 19)
        return 0;
    if (a[i][j] == stone) {
        tt = tt + 1;
        xiazuo(i + 1, j - 1, stone);
    }
    return 0;
}
int main()
{
    int i, j;
    int round;
    cin >> round;
    while (round--) {
        int flag = 0;
        for (i = 1; i < 20; i++)
            for (j = 1; j < 20; j++)
                cin >> a[i][j];
        for (i = 1; i < 20 && flag == 0; i++)
            for (j = 1; j < 20 && flag == 0; j++) {
                if (a[i][j] == 1) {
                    tt = 1;
                    you(i, j + 1, 1);
                    if (tt == 5) {
                        if (a[i][j - 1] != 1) { //防止6颗的情况！
                            flag = 1;
                            cout << 1 << endl;
                            cout << i << " " << j << endl;
                        }
                    }
                    tt = 1;
                    xia(i + 1, j, 1);
                    if (tt == 5) {
                        if (a[i - 1][j] != 1) {
                            flag = 1;
                            cout << 1 << endl;
                            cout << i << " " << j << endl;
                        }
                    }
                    tt = 1;
                    xiayou(i + 1, j + 1, 1);
                    if (tt == 5) {
                        if (a[i - 1][j - 1] != 1) {
                            flag = 1;
                            cout << 1 << endl;
                            cout << i << " " << j << endl;
                        }
                    }
                    tt = 1;
                    xiazuo(i + 1, j - 1, 1);
                    if (tt == 5) {
                        if (a[i - 1][j + 1] != 1) {
                            flag = 1;
                            cout << 1 << endl;
                            cout << i + 4 << " " << j - 4 << endl; //要输出最左，最上的点
                        }
                    }
                } else if (a[i][j] == 2) {
                    tt = 1;
                    you(i, j + 1, 2);
                    if (tt == 5) {
                        if (a[i][j - 1] != 2) {
                            flag = 1;
                            cout << 2 << endl;
                            cout << i << " " << j << endl;
                        }
                    }
                    tt = 1;
                    xia(i + 1, j, 2);
                    if (tt == 5) {
                        if (a[i - 1][j] != 2) {
                            flag = 1;
                            cout << 2 << endl;
                            cout << i << " " << j << endl;
                        }
                    }
                    tt = 1;
                    xiayou(i + 1, j + 1, 2);
                    if (tt == 5) {
                        if (a[i - 1][j - 1] != 2) {
                            flag = 1;
                            cout << 2 << endl;
                            cout << i << " " << j << endl;
                        }
                    }
                    tt = 1;
                    xiazuo(i + 1, j - 1, 2);
                    if (tt == 5) {
                        if (a[i - 1][j + 1] != 2) {
                            flag = 1;
                            cout << 2 << endl;
                            cout << i + 4 << " " << j - 4 << endl;
                        }
                    }
                }
            }
        if (flag == 0)
            cout << 0 << endl;
    }

    return 0;
}
