#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#define MAXN 100005

using namespace std;

int n;
int energy[MAXN];
string words[MAXN];
string rev[MAXN];
long long dp[MAXN][2]; // dp[n][0] is energy to sort suffix starting at n
                       // dp[n][1] is energy to sort suffix starting at n with words[n] reversed.

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> energy[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> words[i];
    rev[i] = words[i];
    reverse(rev[i].begin(), rev[i].end());
  }

  memset(dp, -1, sizeof(dp));
  dp[n - 1][0] = 0;
  dp[n - 1][1] = energy[n - 1];

  for (int i = n - 2; i >= 0; --i) {
    for (int k = 0; k < 2; ++k) {
      for (int l = 0; l < 2; ++l) {
        string cur = k ? rev[i] : words[i];
        string next = l ? rev[i + 1] : words[i + 1];

        //cout << cur << ' ' << next << (cur <= next) << '\n';

        if (cur <= next and dp[i + 1][l] != -1) {
          long long cost = dp[i + 1][l] + (k ? energy[i] : 0);

          if (dp[i][k] == -1) {
            //cout << "dp[" << i << "][" << k << "] = " << cost << '\n';
          } else {
            //cout << "dp[" << i << "][" << k << "] = min(" << dp[i][k] << ", " << cost << ");\n";
          }

          dp[i][k] = dp[i][k] == -1 ? cost : min(dp[i][k], cost);
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    //cout << dp[i][0] << ' ' << dp[i][1] << '\n';
  }

  if (dp[0][0] == -1) {
    cout << dp[0][1] << '\n';
  } else if (dp[0][1] == -1) {
    cout << dp[0][0] << '\n';
  } else {
    cout << min(dp[0][0], dp[0][1]) << '\n';
  }

  return 0;
}
