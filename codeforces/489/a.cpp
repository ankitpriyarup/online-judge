#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;

int N;
int a[3003], b[3003];

void swap(int x, int y) {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

void print() {
    cout << "A:";
    for (int i = 0; i < N; i++) {
        cout << " " << a[i];
    }
    cout << '\n';
    cout << "B:";
    for (int i = 0; i < N; i++) {
        cout << " " << b[i];
    }
    cout << '\n';
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    vector<pair<int, int> > ans;
    sort(b, b + N);
    for (int i = 0; i < N; i++) {
        //print();
        if (a[i] == b[i]) {
            continue;
        }
        for (int j = i + 1; j < N; j++) {
            if (a[j] == b[i]) {
                ans.push_back(make_pair(i, j));
                swap(i, j);
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for (vector<pair<int, int> >::iterator it = ans.begin(); it != ans.end(); it++) {
        cout << it->first << " " << it->second << '\n';
    }

    return 0;
}
