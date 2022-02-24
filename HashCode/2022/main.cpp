#include <bits/stdc++.h>

using namespace std;
typedef pair<string, int> skill;

class Contributor
{
public:
    string name;
    vector<skill> skills;
};

vector<Contributor *> contributors;

class Project
{
public:
    string name;
    int daysToComplete;
    int scoreAwarded;
    int bestBefore;
    vector<skill> skills;
};

vector<Project *> projects;

void parseContributors(int cnt)
{
    while (cnt--) {
        char name[22];
        int n;
        scanf("%s %d", name, &n);

        Contributor *contributor = new Contributor;
        contributor->name = name;
        contributor->skills = vector<skill>();

        for (int i = 0; i < n; i++) {
            int tmp;
            scanf("%s %d", name, &tmp);

            contributor->skills.push_back({name, tmp});
        }

        contributors.push_back(contributor);
    }
}

void parseProjects(int cnt)
{
    while (cnt--) {
        char name[22];
        int d, s, b, r;
        scanf("%s %d %d %d %d", name, &d, &s, &b, &r);

        Project *project = new Project;
        project->name = name;
        project->daysToComplete = d;
        project->scoreAwarded = s;
        project->bestBefore = b;
        project->skills = vector<skill>();

        for (int i = 0; i < r; i++) {
            int tmp;
            scanf("%s %d", name, &tmp);
            project->skills.push_back({name, tmp});
        }

        projects.push_back(project);
    }
}

void printParsed()
{
    printf("Contributors\n");
    for (const auto &data : contributors) {
        printf("%s ->", data->name.c_str());

        for (const auto &data2 : data->skills) {
            printf(" %s:%d", data2.first.c_str(), data2.second);
        }
        printf("\n");
    }
    printf("===\n");

    printf("Projects\n");
    for (const auto &data : projects) {
        printf("%s -> ", data->name.c_str());
        printf("%d %d %d ->", data->daysToComplete, data->scoreAwarded,
               data->bestBefore);

        for (const auto &data2 : data->skills) {
            printf(" %s:%d", data2.first.c_str(), data2.second);
        }
        printf("\n");
    }
    printf("===\n");
}

int main()
{
    int c, p;
    scanf("%d %d", &c, &p);

    parseContributors(c);
    parseProjects(p);
    // printParsed();

    

    return 0;
}
