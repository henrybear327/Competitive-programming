#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while(ncase--) {
		int p, r;
		scanf("%d %d", &p, &r);

		char vote[p][r];
		memset(vote, '\0', sizeof(vote));
		for(int i = 0; i < p; i++) {
			char inp[10000];
			for(int j = 0; j < r; j++) {
				scanf("%s", inp);
				vote[i][j] = inp[0];
			}
		}
		
		bool out[p];
		memset(out, false, sizeof(out));
		for(int j = 0; j < r; j++) {
			int yes = 0, no = 0;
			for(int i = 0; i < p; i++) {
				if(out[i] == false) {
					if(vote[i][j] == 'Y')
						yes++;
					else
						no++;
				}
			}
			
			if(yes == no || yes == 0 || no == 0)
				continue;
			for(int i = 0; i < p; i++) {	
				if(no < yes) {
					if(vote[i][j] == 'Y')
						out[i] = true;
				} else {
					if(vote[i][j] == 'N')
						out[i] = true;
				}
			}
		}
		
		vector<int> ans;
		for(int i = 0; i < p; i++) {
			if(out[i] == false)
				ans.push_back(i);
		}
		
		for(int i = 0; i < (int)ans.size(); i++)
			printf("%d%c", ans[i] + 1, i == (int)ans.size() - 1 ? '\n' : ' ');
	}

	return 0;
}
