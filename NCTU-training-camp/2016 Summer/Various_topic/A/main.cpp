#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    map<int, int> idx;
    int numbering = 0;
    int k1;
    string p1 = "";
    scanf("%d", &k1);
    for(int i = 0; i < k1; i++) {
	int cur;
	scanf("%d", &cur);
	idx[numbering] = cur;
	p1 += (numbering++ + '0');
    }

    int k2;
    string p2 = "";
    scanf("%d", &k2);
    for(int i = 0; i < k2; i++) {
	int cur;
	scanf("%d", &cur);
	idx[numbering] = cur;
	p2 += (numbering++ + '0');
    }

    map< pair<string, string>, int > r;
    r.insert(make_pair(make_pair(p1, p2), 0));
    // printf("%s : %s\n", p1.c_str(), p2.c_str());
    
    int round = 1;
    while(1) {
	string p11 = "", p22 = "";
	/*
	printf("%s : %s\n", p1.c_str(), p2.c_str());
	printf("p1 value:\n");
	for(int i = 0; i < (int)p1.length(); i++)
	    printf("%d%c", idx[p1[i] - '0'], i == (int)p1.length() - 1? '\n' : ' ');
	printf("p2 value:\n");
	for(int i = 0; i < (int)p2.length(); i++)
	    printf("%d%c", idx[p2[i] - '0'], i == (int)p2.length() - 1? '\n' : ' ');
	*/

	if(idx[p1[0] - '0'] < idx[p2[0] - '0']) {
	    p11 = p1.length() > 1 ? p1.substr(1, p1.length() - 1) : "";
	    p22 = (p2.length() > 1 ? p2.substr(1, p2.length() - 1) : "") + p1[0] + p2[0];
	} else {
	    p11 = (p1.length() > 1 ? p1.substr(1, p1.length() - 1) : "") + p2[0] + p1[0];
	    p22 = p2.length() > 1 ? p2.substr(1, p2.length() - 1) : "";
	}
	// printf("pp %s %s\n", p11.c_str(), p22.c_str());
	p1 = p11;
	p2 = p22;
	
	//printf("\n\nRound %d\n", round);
	if(p1.length() == 0 || p2.length() == 0) {
	    printf("%d %d\n", round, p1.length() == 0 ? 2 : 1);
	    break;
	}
	if(r.find(make_pair(p1, p2)) == r.end())
	    r.insert(make_pair(make_pair(p1, p2), round++));
	else {
	    printf("-1\n");
	    break;
	}
    }

    return 0;
}
