#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

struct node {
    string name;
    vector<int> child;
} data[1111];

typedef pair<string, int> vsi; 
bool cmp(vsi a, vsi b)
{
    if(b.second == a.second)
	return a.first < b.first;
    return b.second < a.second;
}

int main()
{
    int ncase;
    char inp[100000];
    fgets(inp, 100000, stdin);
    sscanf(inp, "%d", &ncase);
    for(int kk = 0; kk < ncase; kk++) {
	for(int i = 0; i < 1111; i++) {
	    data[i].name = "";
	    data[i].child.clear();
	}
	int useMe = 0;

	int n, d;
	fgets(inp, 100000, stdin);
	sscanf(inp, "%d %d", &n, &d);
	    
	map< string, int > pool;

	for(int i = 0; i < n; i++) {
	    int term = 0;
	    fgets(inp, 100000, stdin);

	    char *str = strtok(inp, " \n"), *par;
	    // int childCnt = 0;
	    while(str != NULL) {
		if(term == 0) {
		    // parent name
		    par = str;
		} else if(term == 1) {
		    // child count
		    // childCnt = atoi(str);
		    str = strtok(NULL, " \n");
		    term++;
		    continue;
		} else {
		    // child name
		    string parName = par;
		    string childName = str;
		    
		    map< string, int >::iterator parIt, childIt; 
		    if( ( parIt = pool.find(parName) ) != pool.end()) {
			// parent exist
			if( (childIt = pool.find(childName) ) != pool.end()) {
			    // child exist
			    data[parIt->second].child.push_back(childIt->second);
			} else {
			    // child disappear
			    data[useMe].name = childName;
			    data[parIt->second].child.push_back(useMe);
			    pool.insert(make_pair(childName, useMe));
			    useMe++;
			}
		    } else {
			// parent disappear
			if( (childIt = pool.find(childName) ) != pool.end()) {
			    // child exist
			    data[useMe].name = parName;
			    data[useMe].child.push_back(childIt->second);
			    pool.insert(make_pair(parName, useMe));
			    useMe++;
			} else {
			    // child disappear
			    data[useMe].name = parName;
			    data[useMe + 1].name = childName;
			    data[useMe].child.push_back(useMe + 1);

			    pool.insert(make_pair(parName, useMe));
			    pool.insert(make_pair(childName, useMe + 1));
			    useMe += 2;
			}
		    }
		}
		
		term++;
		str = strtok(NULL, " \n");
	    }
	}
	
	vector< pair<string, int > > ans;
	for(auto i : pool) {
	    // bfs
	    queue< ii > q;
	    q.push(ii(i.second, 0) );
	    int cnt = 0;
	    while(q.empty() == false) {
		ii cur = q.front();

		if(cur.second == d) {
		    cnt = q.size();
		    break;
		}
		q.pop();

		for(auto j : data[cur.first].child) {
		    q.push(ii(j, cur.second + 1));
		}
	    }
	    
	    if(cnt != 0)
		ans.push_back(make_pair(i.first, cnt));
	}
	
	sort(ans.begin(), ans.end(), cmp);
	printf("Tree %d:\n", kk + 1);
	for(int i = 0; i < min(3, (int)ans.size()); i++) {
	    printf("%s %d\n", ans[i].first.c_str(), ans[i].second);
	}

	if(ans.size() >= 3) {
	    for(int i = 3; i < (int)ans.size(); i++) {
		if(ans[i - 1].second == ans[i].second)
		    printf("%s %d\n", ans[i].first.c_str(), ans[i].second);
		else
		    break;
	    }
	}
	if(kk != ncase - 1)
	    printf("\n");
    }
	
    return 0;
}
