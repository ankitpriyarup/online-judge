#include <iostream>
#include <cstring>

using namespace std;

int n, m;
char grid[102][102];
int groupings[102];
int new_groupings[102];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }
  memset(groupings, 0, sizeof(groupings));

  int ans = 0;
  for (int j = 0; j < m; ++j) {
    /*
    cout << j << ":";
    for (int i = 0; i < n; ++i) {
      cout << " " << groupings[i];
    }
    cout << '\n';
    */
    // check for an inversion
    bool inversion = false;
    for (int i = 0; i < n; ++i) {
      for (int k = i + 1; k < n; ++k) {
        if (grid[i][j] > grid[k][j] and groupings[i] == groupings[k]) {
          //cout << "Inversion " << i << " " << k << " " << j << '\n';
          inversion = true;
          break;
        }
      }
    }

    if (inversion) {
      ans++;
    } else {
      // update groupings
      int group = 0;
      char last = grid[0][j];
      for (int i = 0; i < n; ++i) {
        if (grid[i][j] != last or (i > 0 and groupings[i] != groupings[i - 1])) {
          ++group;
        }
        new_groupings[i] = group;
        last = grid[i][j];
      }
      memcpy(groupings, new_groupings, sizeof(groupings));
    }
  }

  cout << ans << '\n';
  return 0;
}
