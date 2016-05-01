#include <iostream>
#include <queue>

using namespace std;

int n, k, q;
int t[150005];
int vals[6];
int main() {
    cin >> n >> k >> q;

    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    int type, id;
    priority_queue<int> pq;
    int i;
    while (q-- > 0) {
        cin >> type >> id;
        id--;
        if (type == 1) {
            pq.push(t[id]);
            //cout << "Inserted " << t[id] << '\n';
        } else {
            bool found = false;
            for (i = 0; !pq.empty() && i < k; ++i) {
                vals[i] = pq.top();
                pq.pop();
                //cout << "Removed " << vals[i] << '\n';
                if (vals[i] == t[id])
                    found = true;
            }

            if (found)
                cout << "YES\n";
            else
                cout << "NO\n";

            for (int j = 0; j < i; ++j) {
                pq.push(vals[j]);
                //cout << "Inserted " << vals[j] << '\n';
            }
        }
    }
    return 0;
}
