#include <bits/stdc++.h>

using namespace std;

#define N 600010
#define DEBUG 0
struct node {
    int child[3]; //a b c
    bool ending;
} trie[N];

int freeNode;
void insert(string &str, int pos, int node)
{
#if DEBUG == 1
    printf("%s %d %d\n", str.c_str(), pos, node);
#endif

    if(pos == (int)str.length()) {
	trie[node].ending = true;
#if DEBUG == 1
        printf("%d has end\n", node);
#endif
    } else {
	// find which way to go
	int c = str[pos] - 'a';
	if(trie[node].child[c] == 0) // give a new node
	    trie[node].child[c] = freeNode++;
	insert(str, pos + 1, trie[node].child[c]);
    }
}

bool query(string &str, int pos, int node, bool error)
{
#if DEBUG == 1
    printf("%s %d %d %d\n", str.c_str(), pos, node, error);
#endif

    if(pos == (int)str.length()) {
	if(trie[node].ending == true)
	    return error; // no error is not allowed, we need at least one error
	return false; // no word ends here...
    }
    
    for(int i = 0; i < 3; i++) {
	if(trie[node].child[i] == 0)
	    continue;

	if(str[pos] - 'a' != i && error == true)
	    continue;
	if(query(str, pos + 1, trie[node].child[i], error || (str[pos] - 'a' != i ? true : false)))
	    return true;
    }
    return false;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    // insert strings into trie
    // root is 0
    memset(trie, 0, sizeof(trie));
    freeNode = 1;

    for(int i = 0; i < n; i++) {
	char inp[N];
	scanf("%s", inp);

	string str = inp;
	insert(str, 0, 0);
    }

    for(int i = 0; i < m; i++) {
	char inp[N];
	scanf("%s", inp);
	string str = inp;
	if(query(str, 0, 0, false) == true)
	    printf("YES\n");
	else
	    printf("NO\n");
    }

    return 0;
}
