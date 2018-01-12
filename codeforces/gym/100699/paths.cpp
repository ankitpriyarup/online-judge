#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;

ll n;

bool done[15][15][15][15];
ll save[15][15][15][15];
ll dp(int a, int b, int c, int w, int deb){
    if(a==0 and b == 0 and c == 0){
        return 1;
    }
    if(done[a][b][c][w])
        return save[a][b][c][w];
    done[a][b][c][w] = true;
    int A[5];
    A[0] = a;
    A[1] = b;
    A[2] = c;

    ll ans = 0;
    for(int i=0; i<3; i++){
        if(A[i] == 0 or i == w) continue;
        A[i]--;
        ans += dp(A[0], A[1], A[2], i, deb+1);
        A[i]++;
    }
    save[a][b][c][w] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cout<<dp(n-1, n, n, 0, 0) * 3<<endl;
    return 0;
}
