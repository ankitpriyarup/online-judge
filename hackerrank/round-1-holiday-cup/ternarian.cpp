#include <iostream>
#include <vector>

using namespace std;

void recurse(int value, vector<int>& left_pan, vector<int>& right_pan, int pow) {
    if (pow == 0) return;

    if (pow >= value and pow - value <= value) {
        right_pan.push_back(pow);
        recurse(pow - value, right_pan, left_pan, pow / 3);
    } else if (pow <= value and value - pow <= value) {
        right_pan.push_back(pow);
        recurse(value - pow, left_pan, right_pan, pow / 3);
    } else {
        recurse(value, left_pan, right_pan, pow / 3);
    }
}

int main() {
    int N, x;
    cin >> N;
    while (N-- > 0) {
        cin >> x;
        int p = 1;

        while (p < x) {
            p *= 3;
        }

        vector<int> left_pan, right_pan;
        recurse(x, left_pan, right_pan, p);

        cout << "left pan:";
        for (int i = 0; i < left_pan.size(); ++i) {
            cout << ' ' << left_pan[i];
        }
        cout << '\n';
        cout << "right pan:";
        for (int i = 0; i < right_pan.size(); ++i) {
            cout << ' ' << right_pan[i];
        }
        cout << '\n';

        if (N) {
            cout << '\n';
        }
    }
    return 0;
}
