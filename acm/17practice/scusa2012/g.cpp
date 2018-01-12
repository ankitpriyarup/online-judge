#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

const int MAX_WAYPOINTS = 105;

using namespace std;
using ll = long long;
using ld = long double;

int num_cases;
int num_waypoints;

int energy, time_remaining;
int cur_x, cur_y;
int progress;

int waypoint_x[MAX_WAYPOINTS];
int waypoint_y[MAX_WAYPOINTS];

int waypoint_energy[MAX_WAYPOINTS];
int waypoint_time[MAX_WAYPOINTS];

void read_waypoint(int i) {
    char x_dir, y_dir;
    
    cin >> waypoint_x[i] >> x_dir >> waypoint_y[i] >> y_dir;
    cin >> waypoint_energy[i] >> waypoint_time[i];

    if (x_dir == 'S') {
        waypoint_x[i] *= -1;
    }

    if (y_dir == 'W') {
        waypoint_y[i] *= -1;
    }
}

void move_to(int x, int y) {
    ld dist = sqrt((x - cur_x) * (x - cur_x) + (y - cur_y) * (y - cur_y));

    int idist = (int) dist;
    int steps = idist / 20;

    for (int step = 0; step < steps; step++) {
        while (energy < 1) {
            time_remaining -= 12 - progress;
            progress = 0;
            energy++;
        }

        energy--;
        progress += 4;
        energy += progress / 12;
        progress %= 12;
        time_remaining -= 4;
    }
    
    cur_x = x;
    cur_y = y;
}

void run_experiment(int req_energy, int req_time) {
    if (energy < req_energy) {
        time_remaining -= 12 - progress;
        progress = 0;
        energy++;
        time_remaining -= (req_energy - energy) * 12;
        energy = req_energy;
    }

    energy -= req_energy;
    time_remaining -= req_time;

    energy += req_time / 12;
    progress += req_time % 12;
    energy += progress / 12;
    progress %= 12;
}

bool solve() {
    cur_x = 0;
    cur_y = 0;

    progress = 0;

    cin >> energy >> time_remaining >> num_waypoints;

    for (int i = 1; i <= num_waypoints; i++) {
        read_waypoint(i);
    }

    for (int i = 1; i <= num_waypoints; i++) {
        move_to(waypoint_x[i], waypoint_y[i]);
        run_experiment(waypoint_energy[i], waypoint_time[i]);
        if (time_remaining < 0) break;
    }

    return time_remaining >= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> num_cases;

    for (int case_num = 1; case_num <= num_cases; case_num++) {
        if (solve()) {
            cout << "Mission #" << case_num << " is possible.\n";
        } else {
            cout << "Mission #" << case_num << " is impossible.\n";
        }
    }
    return 0;
}
