#include <iostream>
#include <unordered_map>

using namespace std;

int p;
int x[70];
int y[70];
int z[70];

double dist[70][70];

unordered_map<string, int> rev;

double euclidean(int i, int j) {
    double xd = x[i] - x[j];
    double yd = y[i] - y[j];
    double zd = z[i] - z[j];
    return sqrt(xd * xd + yd * yd + zd * zd);
}

int main() {
    int T;
    cin >> T;
    int w, a, b, q;
    char name[80];

    for (int case_num = 1; case_num <= T; ++case_num) {
        cout << "Case " << case_num << ":\n";
        rev.clear();
        cin >> p;
        for (int i = 0; i < p; ++i) {
            cin >> name;
            cin >> x[i] >> y[i] >> z[i];
            rev[name] = i;
        }

        for (int i = 0; i < p; ++i) {
            for (int j = 0; j <= i; ++j) {
                dist[i][j] = euclidean(i, j);
                dist[j][i] = dist[i][j];
            }
        }

        cin >> w;
        for (int i = 0; i < w; ++i) {
            cin >> name;
            a = rev[name];
            cin >> name;
            b = rev[name];
            dist[a][b] = 0;
        }

        for (int k = 0; k < p; ++k) {
            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                }
            }
        }

        cin >> q;
        while (q-- > 0) {
            cout << "The distance from ";
            cin >> name;
            a = rev[name];
            cout << name;

            cout << " to ";

            cin >> name;
            b = rev[name];
            cout << name;

            long long d = (long long)(dist[a][b] + 0.5);
            cout << " is " << d << " parsecs.\n";
        }
    }

    return 0;
}
