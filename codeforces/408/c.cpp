#include <iostream>
#include <vector>

using namespace std;

struct triple {
    int a, b, c;
    triple(int a, int b, int c): a(a), b(b), c(c) {}
};

vector<triple> triples;

void find_triples() {
    for (int a = 1; a <= 1000; a++) {
        for (int b = a + 1; b <= 1000; b++) {
            for (int i = 0; i <= 100; i++) {
                if (a*a + b*b == i * i) {
                    triples.push_back(triple(a, b, i));
                }
            }
        }
    }
}

int main() {
    find_triples();

    int a, b;
    cin >> a >> b;
    for (int i = 0; i < triples.size(); i++) {
        //cout << triples[i].a << " " << triples[i].b << " " << triples[i].c << '\n';
        if (a % triples[i].c == 0 && b % triples[i].c == 0) {
            cout << "YES" << '\n';
            cout << "0 0" << '\n';
            int a_mult = a / triples[i].c;
            int b_mult = b / triples[i].c;
            int a1 = a_mult * triples[i].a;
            int a2 = a_mult * triples[i].b;
            int b1 = -b_mult * triples[i].b;
            int b2 = b_mult * triples[i].a;
            if (a1 == b1 || a2 == b2) {
                cout << a2 << " " << a1 << '\n';
                cout << -b2 << " " << -b1 << '\n';
            } else {
                cout << a1 << " " << a2 << '\n';
                cout << b1 << " " << b2 << '\n';
            }

            return 0;
        }
    }

    cout << "NO" << '\n';
    return 0;
}
