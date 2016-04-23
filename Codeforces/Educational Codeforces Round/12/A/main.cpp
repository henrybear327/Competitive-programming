#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, ta, b, tb;
    scanf("%d %d %d %d", &a, &ta, &b, &tb);

    int hh, mm;
    scanf("%d:%d", &hh, &mm);

    int s = hh * 60 + mm;
    int t = s + ta;

    int cnt = 0;
    // printf("%d %d\n", s, t);
    for(int bs = 5 * 60; bs <= 23 * 60 + 59; bs += b) {
	if((bs < t) && (bs + tb > s))
	    cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}
