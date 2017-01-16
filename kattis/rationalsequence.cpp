#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int num_cases;
    cin >> num_cases;

    int k;
    string s;
    while (num_cases-- > 0) {
        cin >> k >> s;

        int slash_pos = s.find('/');
        int p = stoi(s.substr(0, slash_pos));
        int q = stoi(s.substr(slash_pos + 1));


        int ans_num = p;
        int ans_den = q;

        if (q == 1) {
            // Go on to a new row
            ans_num = 1;
            ans_den = p + 1;
        } else {
            int left_num = p % q;
            int left_den = q;

            int levels = p / q;

            int parent_num = left_num;
            int parent_den = left_den - left_num;

            int right_num = parent_num + parent_den;
            int right_den = parent_den;

            ans_num = right_num;
            ans_den = right_den + levels * right_num;
        }

        cout << k << ' ' << ans_num << '/' << ans_den << '\n';
    }

    return 0;
}
