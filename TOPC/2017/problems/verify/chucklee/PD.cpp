#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

int TCs;
int N;
char input[10];
int i, x, y, ans;
typedef pair<char, int> PCI;
queue<PCI> Q;
stack<PCI> S;

int main(){
	scanf("%d", &TCs);
	while(TCs--){
		while(!Q.empty()) Q.pop();
		while(!S.empty()) S.pop();
		
		scanf("%d", &N);
		for (i=0; i<N; i++){
			scanf("%s%d", input, &x);
			Q.push(mp(input[0], x));
		}
		
		while(!Q.empty()){
			char curC = Q.front().ft;
			int curN = Q.front().sd;
			Q.pop();
			
			if (!S.empty()) if (S.top().ft==curC){
				curN += S.top().sd;
				S.pop();
			}
			
			if (curN%3) S.push(mp(curC, curN%3));
			if (curN/3) Q.push(mp(curC, curN/3));
		}
		
		ans = 0;
		while(!S.empty()){
			ans += S.top().sd;
			S.pop();
		}
		printf("%d\n", ans);
	}
	
	return 0;
}


