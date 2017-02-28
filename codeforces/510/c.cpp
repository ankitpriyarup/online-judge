#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXA = 26;
const int MAXN = 102;

int n;
vector<int> graph[MAXA];

char strings[MAXN][2 * MAXN];
int in_degree[MAXA];
char out[MAXA + 1];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", strings[i]);
    }

    bool impossible = false;
    memset(in_degree, 0, sizeof(in_degree));
    for (int i = 1; i < n; ++i) {
        // find the first character that differs between s[i - 1] and s[i]
        int a = strlen(strings[i - 1]);
        int b = strlen(strings[i]);
        int j = 0;
        while (j < a and j < b and strings[i - 1][j] == strings[i][j]) {
            ++j;
        }

        // abcd
        // ab

        // no alphabet can fix this 

        if (j >= b and j < a) {
            impossible = true;
        } else if (j < a and j < b) {
            // create an edge
            char before = strings[i - 1][j];
            char after  = strings[i][j];

            // printf("Edge between %c and %c\n", before, after);
            graph[before - 'a'].push_back(after - 'a');
            ++in_degree[after - 'a'];
        }
    }

    for (int i = 0; i < MAXA; ++i) {
        // find a node with 0 in degree
        bool found = false;
        for (int j = 0; j < MAXA; ++j) {
            if (in_degree[j] == 0) {
                in_degree[j] = -1;
                out[i] = j + 'a';
                found = true;

                // printf("%d %c\n", i, out[i]);
                for (int k : graph[j]) {
                    --in_degree[k];
                }

                break;
            }
        }

        if (!found) {
            impossible = true;
            break;
        }
    }

    if (impossible) {
        puts("Impossible");
    } else {
        printf("%s\n", out);
    }

    return 0;
}
