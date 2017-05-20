#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

int n, m;
char name[45], car[45], e[3];

map<string, int> catalog, rent, perkilo;

const int INCONSISTENT = -1;
const int IDLE = 0;
const int HAS_CAR = 1;
map<string, int> states;
map<string, string> owned;
map<string, long long> total_cost;

void read() {
    catalog.clear();
    rent.clear();
    perkilo.clear();
    states.clear();
    owned.clear();
    total_cost.clear();
    scanf("%d %d", &n, &m);

    int p, q, k;
    for (int i = 0; i < n; ++i) {
        scanf("%s %d %d %d", car, &p, &q, &k);

        string c = string(car);

        catalog[c] = p;
        rent[c] = q;
        perkilo[c] = k;
    }
}

void pickup() {
    string s = string(name);
    scanf("%s", car);

    // printf("%s picked up %s\n", name, car);
    if (states[s] != IDLE) {
        states[s] = INCONSISTENT;
        return;
    }

    string c = string(car);
    states[s] = HAS_CAR;
    owned[s] = c;
    total_cost[s] += rent[c];
}

void release() {
    string s = string(name);
    int kilos;
    scanf("%d", &kilos);

    // printf("%s returned %s with %d kilos\n", name, owned[s].c_str(), kilos);
    if (states[s] != HAS_CAR) {
        states[s] = INCONSISTENT;
        return;
    }

    states[s] = IDLE;
    total_cost[s] += perkilo[owned[s]] * kilos;
    owned.erase(owned.find(s));
}

void accident() {
    string s = string(name);
    int severity;
    scanf("%d", &severity);

    // printf("%s had accident with %s with severity %d\n", name, owned[s].c_str(), severity);
    if (states[s] != HAS_CAR) {
        states[s] = INCONSISTENT;
        return;
    }

    total_cost[s] += (severity * catalog[owned[s]] + 99) / 100;
}

void solve() {
    int t;
    while (m-- > 0) {
        scanf("%d %s %s", &t, name, e);
        switch (e[0]) {
            case 'p':
                pickup();
                break;
            case 'r':
                release();
                break;
            case 'a':
                accident();
                break;
        }
    }

    for (const pair<string, int>& kv : states) {
        const string& s = kv.first;
        if (kv.second != IDLE) {
            printf("%s %s\n", s.c_str(), "INCONSISTENT");
        } else {
            printf("%s %lld\n", s.c_str(), total_cost[s]);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        read();
        solve();
    }

    return 0;
}
