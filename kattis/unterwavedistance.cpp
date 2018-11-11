#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

int DEBUG = 0;

ll f(ll a, ll b) {
    return abs(a * a * a - b * b * b);
}

// Get the best score for these two iterators. it1 < it2, from different maps.
ll check(map<int, vector<int>>::iterator it1,
         map<int, vector<int>>::iterator it2,
         int degree,
         const vector<int> g,
         const vector<vector<int>>& graph,
         const vector<map<int, int>>& grav_degree) {
    int lo_grav = it1->first;
    int hi_grav = it2->first;

    ll score = f(lo_grav, hi_grav);
    ll exp_degree = 1LL * it1->second.size() * it2->second.size();

    if (DEBUG) {
        cout << "Actual degree: " << degree << '\n';
        cout << "Needed degree: " << exp_degree << '\n';
    }

    if (degree != exp_degree) {
        // There is some pair of nodes which are not connected. This
        // means we can decrease the larger one by one.
        if (DEBUG)
            cout << "Can decrease: true\n";

        score = min(score, f(lo_grav, hi_grav - 1));
    }

    // Is there some planet connected to a lower gravity system in our
    // set and not all of the higher ones? If so, then we can increase
    // the gravity of the lower one by putting the device in this system.
    bool can_increase = false;

    // This loop looks bad, but iterates over all edges at most once
    for (int u : it1->second) {
        if (DEBUG)
            cout << "u: " << u << '\n';
        for (int v : graph[u]) {
            if (DEBUG)
                cout << "v: " << v << '\n';
            // For the purposes of this calculation, if v is in the set of
            // higher gravity, then we say it is connected to itself.
            int base_deg = (g[v] == hi_grav);

            auto it = grav_degree[v].find(hi_grav);
            int gdeg = base_deg + (it == end(grav_degree[v]) ? 0 : it->second);

            if (DEBUG) {
                cout << "Id: " << v << " has degree " << gdeg << "connecting to grav " << hi_grav << " of the other kind\n";
            }

            can_increase |= gdeg < it2->second.size();
            if (DEBUG and  can_increase) {
            }
        }
    }

    if (can_increase) {
        if (DEBUG)
            cout << "Can increase: true\n";

        score = min(score, f(lo_grav + 1, hi_grav));
    }

    return score;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> g(n);
    vector<bool> is_alien(n);
    int grav;
    string d;

    map<int, vector<int>> humans;
    map<int, vector<int>> aliens;
    for (int i = 0; i < n; ++i) {
        cin >> grav >> d;
        g[i] = grav;
        is_alien[i] = d == "a";
        if (is_alien[i]) {
            aliens[g[i]].push_back(i);
        } else {
            humans[g[i]].push_back(i);
        }
    }

    int m;
    cin >> m;
    int u, v;
    vector<vector<int>> graph(n);
    vector<map<int, int>> grav_degree(n);

    // number of edges connecting different kinds of systems
    // alien gravity, then human
    map<pair<int, int>, int> degrees;

    ll score = 1e18 + 1e9;
    while (m-- > 0) {
        cin >> u >> v;
        --u; --v;

        graph[u].push_back(v);
        graph[v].push_back(u);

        grav_degree[u][g[v]]++;
        grav_degree[v][g[u]]++;

        if (is_alien[u] ^ is_alien[v]) {
            int min_g = min(g[u], g[v]);
            int max_g = max(g[u], g[v]);
            score = min(score, f(min_g + 1, max_g - 1));

            if (is_alien[u]) {
                ++degrees[{g[u], g[v]}];
            } else {
                ++degrees[{g[v], g[u]}];
            }
        }
    }

    auto human_it = begin(humans);
    auto alien_it = begin(aliens);

    while (human_it != end(humans) and alien_it != end(aliens)) {
        // No gravity device.
        score = min(score, f(human_it->first, alien_it->first));

        if (DEBUG) {
            cout << "Processing new pair of buckets:\n";
            cout << "Human grav: " << human_it->first << '\n';
            cout << "Alien grav: " << alien_it->first << '\n';
        }

        int degree = degrees[{alien_it->first, human_it->first}];

        if (human_it->first == alien_it->first) {
            // There's a human and alien planet with the same gravity.
            // Score is already 0
            break;
        } else if (human_it->first < alien_it->first) {
            score = min(score, check(human_it, alien_it, degree, g, graph, grav_degree));
            human_it = next(human_it);
        } else {
            score = min(score, check(alien_it, human_it, degree, g, graph, grav_degree));
            alien_it = next(alien_it);
        }
    }

    cout << score << '\n';

    return 0;
}
