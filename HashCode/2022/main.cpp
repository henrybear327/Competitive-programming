#include <bits/stdc++.h>

using namespace std;
typedef pair<string, int> skill;
typedef pair<int, int> ii;

class Contributor
{
public:
    string name;
    vector<skill> skills;
};

vector<Contributor *> contributors;
vector<bool> taken;

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
map<string, vector<int>> available;

void parseContributors(int cnt)
{
    for (int _i = 0; _i < cnt; _i++) {
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

            available[name].push_back(_i);
        }

        contributors.push_back(contributor);
        taken.push_back(false);
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

class Answer
{
public:
    string projectName;
    vector<int> devs;
};

int ansScore = 0;
vector<Answer> ans;

////// Sol1 ////////

const int MAX_ITERATION_FOR_SIIMULATION = 10000;
const int MAX_MATCHING_ATTEMPTS = 100;

vector<int> match;
vector<int> levelUp;
bool devMatching(int projIndex)
{
    for (int _i = 0; _i < MAX_MATCHING_ATTEMPTS; _i++) {
        vector<int> cand;
        vector<int> up;
        for (const auto &s : projects[projIndex]->skills) {
            cand.push_back(rand() % available[s.first].size());
            up.push_back(-1);
        }

        // check condition
        bool ok = true;
        for (int i = 0; i < (int)cand.size(); i++) {
            if (taken[cand[i]]) {
                ok = false;
                break;
            }
            bool hasMatched = false;
            int idx = -1;
            for (const auto &s : contributors[cand[i]]->skills) {
                idx++;
                if (projects[projIndex]->skills[i].first ==
                    s.first) { // dev has the skill
                    hasMatched = true;

                    // if the level is fulfilled, cont
                    if (projects[projIndex]->skills[i].second <= s.second) {
                        // no op
                    } else if (projects[projIndex]->skills[i].second - 1 == s.second) {
                        // check if mentor is there
                        bool hasMentor = false;
                        for (int j = 0; j < (int)cand.size(); j++) {
                            if (i != j) {
                                for (const auto &tmp : contributors[cand[j]]->skills) {
                                    if (tmp.first == s.first) {
                                        if (tmp.second >= projects[projIndex]->skills[i].second) {
                                            hasMentor = true;
                                            up[i] = idx;
                                        }

                                        break;
                                    }
                                }

                                if (hasMentor)
                                    break;
                            }
                        }

                        // no?
                        if (hasMentor == false) {
                            ok = false;
                        }
                    } else {
                        ok = false;
                    }

                    break;
                }
            }

            if (hasMatched == false)
                ok = false;
            if (ok == false)
                break;
        }

        if (ok) {
            match = cand;
            levelUp = up;
            return true;
        }
    }

    return false;
}

void sol1()
{
    // state: project order
    // score: just accumulated score
    for (int _i = 0; _i < MAX_ITERATION_FOR_SIIMULATION; _i++) {
        srand(time(NULL));
        for (int i = 0; i < (int)projects.size(); i++) {
            swap(projects[rand() % projects.size()],
                 projects[rand() % projects.size()]);
        }

        // start
        int curScore = 0;
        vector<Answer> curAnswer;
        int curTime = 0;
        priority_queue<ii, vector<ii>, greater<ii>> pq;

        for (int i = 0; i < (int)projects.size(); i++) {
            // pop head proj out

            // check pq for proj that has ending time smaller than the starting time
            // of current proj
            while (pq.size() > 0) {
                if (pq.top().first <= curTime) {
                    // return devs
                    for (auto m : curAnswer[pq.top().second].devs) {
                        taken[m] = false;
                    }

                    // add score
                    curScore += projects[pq.top().second]->scoreAwarded;

                    pq.pop();
                } else {
                    break;
                }
            }

            // check if it's still worth doing the popped proj, attempt randomized
            // matching of the devs
            if (devMatching(i)) {
                // if ok, add to ans, and add to pq, rm used dev from avail list, update
                // the score if penalty will apply, level up devs if required
                curAnswer.push_back({projects[i]->name, match});

                pq.push({curTime + projects[i]->daysToComplete, curAnswer.size() - 1});

                for (auto m : match) {
                    taken[m] = true;
                }

                if (curTime + projects[i]->daysToComplete - 1 >
                    projects[i]->bestBefore) {
                    // 0 + 3 2
                    projects[i]->scoreAwarded -=
                        curTime + projects[i]->daysToComplete - projects[i]->bestBefore;
                }

                for (int x = 0; x < (int)levelUp.size(); x++) {
                    if (levelUp[x] != -1) {
                        contributors[x]->skills[levelUp[x]].second++;
                    }
                }

                curTime += projects[i]->daysToComplete; // FIXME
            } else {
                // if not, skip (let project ordering does its adjust afterwards)
            }
        }
        // at the end, pop all the pq out and update score
        while (pq.size() > 0) {
            curScore += projects[pq.top().second]->scoreAwarded;
            pq.pop();
        }

        if (_i == 0)
            ans = curAnswer;
        else {
            if (curScore > ansScore) {
                ans = curAnswer;
            }
        }

        // prepare for the next round
    }
}

////// Sol1 ////////

void printAnswer()
{
    printf("%d\n", (int)ans.size());
    for (const auto &tmp : ans) {
        printf("%s\n", tmp.projectName.c_str());
        for (int i = 0; i < (int)tmp.devs.size(); i++) {
            printf("%s%c", contributors[tmp.devs[i]]->name.c_str(),
                   i == (int)tmp.devs.size() - 1 ? '\n' : ' ');
        }
    }
}

int main()
{
    int c, p;
    scanf("%d %d", &c, &p);

    parseContributors(c);
    parseProjects(p);
    // printParsed();

    sol1();

    printAnswer();

    return 0;
}
