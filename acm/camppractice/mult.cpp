#include<iostream>

using namespace std;
int N, M, K;
int main() {
    cin >> K;
    for(int ll=0;ll<K;ll++) {
        cin >> N >> M;
        int rowOne = 0;
        for(int i=1;i<=M;i++) {
            rowOne += i;
        }
        int ans = rowOne;
        for(int row=2;row<=N;row++) {
            ans += row*rowOne;
        }
        cout << ans << '\n';
    }
    return 0;
}
