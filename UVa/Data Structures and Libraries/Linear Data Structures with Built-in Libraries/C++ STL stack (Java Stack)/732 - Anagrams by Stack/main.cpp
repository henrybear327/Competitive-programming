#include <cstdio>
#include <string>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

#define N 10000

char ans[2 * N];
char inp[N], tar[N];
const char cand[2] = {'i', 'o'};
int len;

#define DEBUG 0
void dfs(int pos, int cnti, int cnto, stack<int> s, int next, int idx)
{
#if DEBUG == 1
	printf("top %d %d %d %d %d\n", pos, cnti, cnto, next, idx);
	for(int i = 0; i < 2 * len; i++)
		printf("%c%c", ans[i], i == 2 * len - 1 ? '\n' : ' '); 
#endif

	if(pos == 2 * len) {
		for(int i = 0; i < 2 * len; i++)
			printf("%c%c", ans[i], i == 2 * len - 1 ? '\n' : ' '); 
		return;
	}
	for(int i = 0; i < 2; i++) {
		if(cand[i] == 'i') {
			// check 
			if(cnti == 0)
				continue;
			ans[pos] = 'i';
			s.push(inp[next]);
			dfs(pos + 1, cnti - 1, cnto, s, next + 1, idx);
			s.pop();
		} else {
			if(cnto == 0 || cnti == len)
				return;
#if DEBUG == 1
			printf("case 2: %d %d %d %d %d\n", pos, cnti, cnto, next, idx);
			if(s.empty())
				return;
			printf("%c %c %d\n", s.top(), tar[idx], idx);
#endif
			if(s.empty())
				return;
			if(s.top() != tar[idx])
				return;
			s.pop();
			ans[pos] = 'o';
			dfs(pos + 1, cnti, cnto - 1, s, next, idx + 1);
		}
	}
}

int main()
{
	while(scanf("%s %s", inp, tar) == 2) {
		len = strlen(inp);
		
		printf("[\n");
		stack<int> s;
		if(strlen(inp) == strlen(tar)) // really? really dude?
			dfs(0, len, len, s, 0, 0);
		printf("]\n");
	}

    return 0;
}
