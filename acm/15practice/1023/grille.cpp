#include <iostream>

using namespace std;

int main() {
    int N;
    char grille[1001][1001];
    char text[1001][1001];
    while (cin >> N) {
        if (N == 0) {
            break;
        }
        string wtf;
        for (int i = 0; i < N; ++i) {
            cin >> wtf;
            for (int j = 0; j < N; ++j) {
                grille[i][j] = wtf[j];
            }
        }

        for (int i = 0; i < N; ++i) {
            cin >> text[i];
        }

        string ans = "";
        for (int rot = 0; rot < 4; ++rot) {
            /* print_grille
            cout << '\n' << '\n';
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    cout << grille[i][j];
                }
                cout << '\n';
            }
            cout << '\n';
            */

            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (grille[i][j] == 'O') {
                        ans += text[i][j];
                    }
                }
            }

            // transpose
            for (int i = 0; i < N; ++i) {
                for (int j = i; j < N; ++j) {
                    char temp = grille[i][j];
                    grille[i][j] = grille[j][i];
                    grille[j][i] = temp;
                }
            }

            // reflect
            for (int i = 0; i < N; ++i) {
                int start = 0;
                int end = N - 1;
                while (start < end) {
                    char temp = grille[i][start];
                    grille[i][start] = grille[i][end];
                    grille[i][end] = temp;
                    start++;
                    end--;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
