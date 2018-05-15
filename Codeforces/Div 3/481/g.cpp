#include <bits/stdc++.h>

using namespace std;

struct Record {
    int dateOfExam, daysLeft, exam;

    bool operator<(const Record &others) const
    {
        return dateOfExam > others.dateOfExam;
    }
};

struct Exam {
    int start, end, prepare, who;
};

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    Exam exams[m];
    int schedule[n];
    memset(schedule, 0, sizeof(schedule));
    for (int i = 0; i < m; i++) {
        int s, d, c;
        scanf("%d %d %d", &s, &d, &c);
        s--;
        d--;

        exams[i] = Exam{s, d, c, i + 1};
        schedule[d] = m + 1;
    }
    sort(exams, exams + m,
         [](const Exam &a, const Exam &b) -> bool { return a.start < b.start; });

    priority_queue<Record> pq;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        while (idx < m && exams[idx].start == i) {
            pq.push(Record{exams[idx].end, exams[idx].prepare, exams[idx].who});
            idx++;
        }

        if (schedule[i] == 0) {
            if (pq.size() > 0) {
                auto cur = pq.top();
                // printf("%d cur %d\n", i + 1, cur.exam);
                pq.pop();
                if (cur.dateOfExam <= i) {
                    printf("-1\n");
                    return 0;
                }
                schedule[i] = cur.exam;

                cur.daysLeft--;
                if (cur.daysLeft > 0) {
                    pq.push(cur);
                }
            }
        }
    }

    if (pq.size() == 0) {
        for (auto i : schedule)
            printf("%d ", i);
        puts("");
    } else
        printf("-1\n");

    return 0;
}
