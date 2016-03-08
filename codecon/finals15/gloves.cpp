#include <iostream>
#include <vector>

using namespace std;

int N;

string reverse(string a) {
    string b = a;
    reverse(b.begin(), b.end());

    return b;
}

int main() {
    cin >> N;
    vector<string> v1;
    vector<string> v2;
    string s;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        v1.push_back(s);
        v2.push_back(reverse(s));

        if (v1[i] != v2[i]) {
            ans += 1;
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (int i = 0; i < N; ++i) {
        if (v1[i] != v2[i]) {
            ans = -1;
            break;
        }
    }

    cout << (ans >= 0 ? ans / 2 : ans) << '\n';
    return 0;
}
