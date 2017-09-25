/**
 *    author:  tourist
 *    created: 23.09.2017 15:13:56
 **/
#include <bits/stdc++.h>

using namespace std;

string let = "RYGB";

int main()
{
    int h, w, d;
    cin >> h >> w >> d;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int x = ((i + j) % (2 * d) + (2 * d)) % (2 * d) / d;
            int y = ((i - j) % (2 * d) + (2 * d)) % (2 * d) / d;
            putchar(let[2 * x + y]);
        }
        putchar('\n');
    }
    return 0;
}
