/*
ID: rednano1
PROG: job
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <functional>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N, M1, M2;
int a[33], b[33];
vector<int> a_times;

bool can_finish(int finish_time) {
    int free_by[33];
    for (int i = 0; i < M2; ++i) {
        free_by[i] = finish_time;
    }

    for (int i = N - 1; i >= 0; --i) {
        int machine = -1;
        int start_time = a_times[i];
        for (int j = 0; j < M2; ++j) {
            //cout << start_time << ' ' << b[j] << ' ' << free_by[j] << '\n';
            if (start_time + b[j] <= free_by[j]) {
                if (machine == -1 or b[j] < b[machine]) {
                    machine = j;
                }
            }
        }

        if (machine == -1)
            return false;

        free_by[machine] -= b[machine];
    }

    return true;
}

int main() {
    ifstream fin("job.in");
    ofstream fout("job.out");

    fin >> N >> M1 >> M2;

    priority_queue<pii, vector<pii>, greater<pii> > pq;

    for (int i = 0; i < M1; ++i) {
        fin >> a[i];
        pq.push(make_pair(a[i], i));
    }

    for (int i = 0; i < M2; ++i) {
        fin >> b[i];
    }

    fin.close();

    for (int i = 0; i < N; ++i) {
        pii cur = pq.top();
        pq.pop();
        int time = cur.first;
        int machine = cur.second;

        a_times.push_back(time);
        pq.push(make_pair(time + a[machine], machine));
    }

    fout << a_times[N - 1] << ' ';

    int lo = 0;
    int hi = 1e9;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (can_finish(mid)) {
            hi = mid;
        } else {
            //cout << "Cannot finish by " << mid << '\n';
            lo = mid;
        }
    }

    fout << hi << '\n';
    fout.close();

    return 0;
}
