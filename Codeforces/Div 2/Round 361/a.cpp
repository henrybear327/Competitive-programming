#include <bits/stdc++.h>

using namespace std;

bool bounded(int x, int y)
{
    if(x == 3) {
	if(y == 0 || y == 2)
	    return false;
	else
	    return true;
    }
    return (0 <= x && x < 3) && (0 <= y && y < 3);
}

int num(char c)
{
    return c - '0';
}

int main()
{
    int key[4][3];
    for(int i = 1; i <= 9; i++)
	key[(i - 1) / 3][(i - 1) % 3] = i;
    key[3][0] = -1;
    key[3][1] = 0;
    key[3][2] = -1;

    int n;
    scanf("%d", &n);
    char inp[10];
    scanf("%s", inp);
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int cnt = 0;
    for(int i = 0; i < 4; i++) {
	for(int j = 0; j < n; j++) {
	    // find pos
	    int x = -1, y;
	    if(num(inp[j]) == 0) {
		x = 3;
		y = 1;
	    } else {
		int tmp = num(inp[j]);
		for(int p = 0; p < 3 && x == -1; p++)
		    for(int q = 0; q < 3; q++)
			if(tmp == key[p][q]) {
			    x = p;
			    y = q;
			    break;
			}
	    }
	    
	    if(bounded(x + dx[i], y + dy[i]) == false) {
		cnt++;
		break;
	    }
	}
    }

    if(cnt == 4)
	printf("YES\n");
    else
	printf("NO\n");

    return 0;
}
