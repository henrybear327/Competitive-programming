#include <bits/stdc++.h>

using namespace std;

const char *color = "RYGB";
// const char* color = "ABCD";

int main()
{
    int h, w, d;
    scanf("%d %d %d", &h, &w, &d);

    int ans[h][w];
    if (d % 2 == 1) {
        for (int i = 0; i < h; i++) {
            int val = 0;
            int offset = (i % 2 == 0 ? 0 : 2);
            for (int j = 0; j < w; j++) {
                ans[i][j] = val + offset;
                val = (val + 1) % 2;
            }
        }

    } else if (d % 2 == 0) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int who = ((i + j) / d) % 2;
                if (who != 0 && (j % d >= d / 2)) {
                    who++;
                }
                ans[i][j] = who;
            }
        }
    } /*else {
      for(int i = 0; i < h; i++) {
          for(int j = 0; j < w; j++) {
              int who = ((i + j) / d) % 2;
              ans[i][j] = who;
          }
      }
  }*/

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            printf("%c", color[ans[i][j]]);
        printf("\n");
    }

    return 0;
}
