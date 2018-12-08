#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct Data {
	int type;
	int func;
	int t;
};

typedef pair<int, int> ii;

class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs) 
	{
		vector<int> res(n, 0);

		vector<Data> log;
		for(int i = 0; i < (int)logs.size(); i++) {
			int func, t;
			char str[10000], *type;
			sscanf(logs[i].c_str(), "%s", str);

			char* tok = strtok(str, ":");
			func = atoi(tok);
			tok = strtok(NULL, ":");
			type = tok;
			tok = strtok(NULL, ":");
			t = atoi(tok);
			printf("%d %c %d\n", func, type[0], t);

			log.push_back(Data{(type[0] == 's' ? 0 : 1), func, t});
		}
		
		stack<int> s;
		s.push(log[0].func);
		for(int i = 1; i < (int)log.size(); i++) {		
			if(log[i].type == 1 && log[i - 1].type == 0) {
				res[log[i].func] += log[i].t - log[i - 1].t + 1;
				s.pop();
			} else if(log[i].type == 0 && log[i - 1].type == 1) {
				int diff = log[i].t - log[i - 1].t - 1;
				if(diff > 0 && s.empty() == false) {
					res[s.top()] += diff;
				}
				s.push(log[i].func);
			} else {
				if(log[i].type == 0) {
					res[log[i - 1].func] += log[i].t - log[i - 1].t;
					s.push(log[i].func);
				} else {
					res[log[i].func] += log[i].t - log[i - 1].t;
					s.pop();
				}
			}

			// printf("%d %d\n", res[0], res[1]);

		}

		return res;
	}
};

/*
int main()
{
	Solution s;
	vector<string> data;
	
	data.push_back("0:start:0");
	data.push_back("1:start:2");
	data.push_back("1:end:5");
	data.push_back("0:end:6");

	data.push_back("0:start:0");
	data.push_back("0:start:2");
	data.push_back("0:end:5");
	data.push_back("1:start:7");
	data.push_back("1:end:7");
	data.push_back("0:end:8");
	vector<int> res = s.exclusiveTime(2, data);
	for(auto i : res) {
		printf("%d ", i);
	}

    return 0;
}
*/
