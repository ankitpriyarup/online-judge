#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
bool adj[30][30];
char a[3], b[3];
char word[2][80];

int main() {
    memset(adj, 0, sizeof(adj));

    for (int i = 0; i < 26; ++i)
        adj[i][i] = 1;

    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; ++i) {
        scanf("%s %s", a, b);
        adj[a[0] - 'a'][b[0] - 'a'] = 1;
    }

    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                adj[i][j] = adj[i][j] or (adj[i][k] and adj[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        scanf("%s %s", word[0], word[1]);
        int l = strlen(word[0]);
        int l2 = strlen(word[1]);
        bool good = (l == l2);
        for (int j = 0; good and j < l; ++j) {
            good &= adj[word[0][j] - 'a'][word[1][j] - 'a'] == 1;
        }

        if (good) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}
