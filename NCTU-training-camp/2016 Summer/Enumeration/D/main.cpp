#include <bits/stdc++.h>

using namespace std;

int r1, r2, c1, c2, d1, d2;

bool used[10], ok;
int arr[4], cnt;
void dfs()
{
    if(cnt == 4) {
	bool tmp = true;
	if(arr[0] + arr[1] != r1)
	    tmp = false;
	if(arr[2] + arr[3] != r2)
	    tmp = false;
	if(arr[0] + arr[2] != c1)
	    tmp = false;
	if(arr[1] + arr[3] != c2)
	    tmp = false;
	if(arr[0] + arr[3] != d1)
	    tmp = false;
	if(arr[1] + arr[2] != d2)
	    tmp = false;
	
	ok = tmp;
	if(ok) {
	    printf("%d %d\n%d %d\n", arr[0], arr[1], arr[2], arr[3]);
	}
	return;
    }

    for(int i = 1; i <= 9 && ok == false; i++) {
	if(used[i] == true)
	    continue;
	arr[cnt++] = i;
	used[i] = true;
	dfs();
	used[i] = false;
	cnt--;
    }
}

int main()
{
    scanf("%d %d %d %d %d %d", &r1, &r2, &c1, &c2, &d1, &d2);
    
    memset(used, false, sizeof(used));
    cnt = 0;
    ok = false;
    dfs();    

    if(ok == false)
	printf("-1\n");

    return 0;
}
