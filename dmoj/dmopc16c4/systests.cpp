#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>

using namespace std;

const int START = 0;
const int QUERY = 1;
const int END = 2;

const int MAXB = 100005;

struct event {
    int type;
    int time;
    int index;

    bool operator<(const event& other) const {
        if (time == other.time) {
            return type < other.type;
        }
        return time < other.time;
    }
};

vector<event> events;
int points[MAXB];

int main() {
    ios_base::sync_with_stdio(false);
    int b;
    scanf("%d", &b);
    int start, end;
    for (int i = 0; i < b; ++i) {
        scanf("%d %d %d", &start, &end, points + i);

        events.push_back({START, start, i});
        events.push_back({END, end, i});
    }

    int f;
    scanf("%d", &f);

    int x;
    for (int i = 0; i < f; ++i) {
        scanf("%d", &x);
        events.push_back({QUERY, x, -1});
    }

    sort(events.begin(), events.end());

    set<int> current;
    set<int> unused;
    for (event ev : events) {
        if (ev.type == START) {
            current.insert(ev.index);
        } else if (ev.type == END) {
            current.erase(ev.index);
        } else if (ev.type == QUERY) {
            unused.insert(current.begin(), current.end());
            current.clear();
        } else {
            printf("ERROR: UNRECOGNIZED TYPE %d\n", ev.type);
        }
    }

    long long ans = 0;
    for (int i = 0; i < b; ++i) {
        if (unused.find(i) == unused.end()) {
            ans += points[i];
        }
    }

    printf("%lld\n", ans);
    return 0;
}
