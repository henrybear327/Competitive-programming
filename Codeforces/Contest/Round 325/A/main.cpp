#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    bool first_one = false;
    int ans = 0;
    int zeros = 0;
    for(int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);

        if(tmp == 1 && first_one == false) {
            first_one = true;
            ans++;
        } else if(first_one == true) {
            if(tmp == 1) {
                if(zeros >= 2) {
                    zeros = 0;
                } else if(zeros == 1) {
                    ans++;
                    zeros = 0;
                }
                ans++;
            } else {
                zeros++;
            }
        }
        //printf("%d %d\n", ans, zeros);
    }

    printf("%d\n", ans);

    return 0;
}
