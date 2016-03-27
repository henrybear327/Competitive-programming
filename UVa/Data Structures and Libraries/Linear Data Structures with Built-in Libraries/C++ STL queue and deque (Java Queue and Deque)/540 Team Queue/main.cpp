#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int index = 1;
    while(scanf("%d", &t) == 1 && t) {
	printf("Scenario #%d\n", index++);

	map<int, int> team_table;
	for(int i = 0; i < t; i++) {
	    int n;
	    scanf("%d", &n);
	    for(int j = 0; j < n; j++) {
		int tmp;
		scanf("%d", &tmp);

		team_table.insert(make_pair(tmp, i));
	    }
	}

	char cmd[100];
	int num;
	queue<int> q[1010];
	int order[1010] = {0}, oidx = 1;
	while(scanf("%s", cmd) == 1) {
	    if(cmd[0] == 'S')
		break;

	    if(cmd[0] == 'E') {
		scanf("%d", &num);
		if(order[team_table[num]] == 0)
		    order[team_table[num]] = oidx++;
		q[team_table[num]].push(num);
	    } else {
		/*
		for(int i = 0; i < t; i++) {
		    if(q[i].empty() == false) {
			printf("%d\n", q[i].front());
			q[i].pop();
			break;
		    }
		}
		*/
		
		int mn = INT_MAX, midx;
		for(int i = 0; i < t; i++) {
		    if(order[i] != 0) {
			if(mn > order[i]) {
			    mn = order[i];
			    midx = i;
			}
		    }
		}

		printf("%d\n", q[midx].front());
		q[midx].pop();


		if(q[midx].empty())
		    order[midx] = 0;
	    }
	}
	printf("\n");
    }

    return 0;
}
