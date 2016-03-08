//Problem        : Pleasant Walk
//Language       : C++11
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits> 

using namespace std;

int R, C;
int side[200][200];
int top[200][200];

int dp[200][200];

int main() {
	cin >> R >> C;

	for (int i = 0; i < 2 * R + 1; ++i) {
        if (i % 2) {
            for (int j = 0; j < C + 1; ++j) {
                cin >> top[i / 2][j];
            }
        } else {
            for (int j = 0; j < C; ++j) {
                cin >> side[i / 2][j];
            }
        }
	}

	memset(dp, -1, sizeof(dp));

	dp[0][0] = 0;
	for (int i = 1; i <= C; ++i) {
		dp[0][i] = dp[0][i - 1] + side[0][i - 1];
	}

	for (int i = 1; i <= C; ++i) {
		dp[i][0] = dp[i - 1][0] + top[i - 1][0];
	}

    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            dp[i][j] = max(dp[i][j - 1] + side[i][j - 1], dp[i - 1][j] + top[i - 1][j]);
        }
    }

    cout << dp[R][C] << '\n';

    return 0;
}

