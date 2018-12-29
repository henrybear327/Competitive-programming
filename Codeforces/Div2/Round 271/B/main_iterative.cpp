#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int inp[n + 1];
    inp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);

        inp[i] = inp[i - 1] + tmp;
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int key;
        scanf("%d", &key);

        int l = 0, r = n;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (inp[mid] < key) { // limit to left
                l = mid; 
            } else if (key < inp[mid]) { // limit to right
                r = mid;
            } else { // spot on!
		r = mid; // crucial step
                break;
	    }
        }

        if (inp[r] == key)
            printf("%d\n", r);
        else
            printf("%d\n", l + 1);
    }

    return 0;
}
