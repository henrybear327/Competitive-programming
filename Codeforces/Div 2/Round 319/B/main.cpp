#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int total, target;
    scanf("%d %d",&total, &target);

    vector<bool> ok(target, false);

    for(int i = 0; i < total; i++) {
        int tmp;
        scanf("%d", &tmp);
        tmp %= target;

        vector<bool> tmp_ok = ok;
        for(int j = 1; j < target; j++) {
            if(tmp_ok[j]) {
                ok[(j + tmp) % target] = true;
            }
        }

        ok[tmp] = true;

        if(ok[0]) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");

	return 0;
}

