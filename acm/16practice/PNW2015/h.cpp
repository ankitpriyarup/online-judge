#include <iostream>

using namespace std;

struct place {
    int x, y;
    string name;

    place(int x, int y, string name): x(x), y(y), name(name) {};
};

int n, s;
vector<place> places;

int get_quad(const place& a, const int s) {
    bool top_half = a.first <
}

bool less(const place& a, const place& b, const int s) {
    int q1 = get_quad(a, s);
    int q2 = get_quad(b, s);
    if (q1 != q2) {
        return q1 < q2;
    } else {

    }
}

bool cmp(const place& a, const place& b) {
    return less(a, b, s);
}

int main() {
    cin >> n >> s;
    ++s;
    int x, y;
    string name;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> name;
    }

    sort(places.begin(), places.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << places[i].name << '\n';
    }

    return 0;
}
