#include<iostream>

using namespace std;
int C, N;
int a[101];
int dp[101][101];
int main() {
    cin >> C;
    for(int ll=1;ll<=C;ll++) {
        cin >> N;
        for(int i=0;i<N;i++) {
            cin >> a[i];
        }
        //lets solve the dp for the range (i, j) i is inclusive j is exclusive
        for(int i=0;i<N;i++) {
            dp[i][i] = 0;
            dp[i][i+1] = a[i];
        }
        for(int dist=2;dist<=N;dist++) {
            for(int i=0;i+dist<=N;i++) {
                //taking a[i] leaves [i+1][i+dist]. opponent either takes [i+1] or [i+dist-1]
                dp[i][i+dist] = max(a[i]+min(dp[i+2][i+dist], dp[i+1][i+dist-1]), 
                        //taking a[i+dist-1] leaves [i][i+dist-1]. opponent either takes [i] or [i+dist-2]
                        a[i+dist-1]+min(dp[i+1][i+dist-1], dp[i][i+dist-2]));
            }
        }
        cout << dp[0][N] << '\n';
    }
    return 0;
}
