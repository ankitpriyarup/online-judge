#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int n, k;
double ans = 0, total;
double D[500][500];
bool Z[500][500];
double bin(int a, int b){
    if(b==1)
        return a;
    if(b==0)
        return 1;
    if(a==b)
        return 1;
    if(b>a)
        return 0;
    if(Z[a][b])
        return D[a][b];
    Z[a][b] = true;
    D[a][b] = bin(a-1, b-1) + bin(a-1, b);
    return D[a][b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    scanf("%d%d", &n, &k);
    total = 1;
    for(int i=1; i<=k; i++){
        total *= 2.0;
    }
    for(int i=0; i<=n-2 and i <=k; i++){
        ans += bin(k, i) * i / total;
    }
    for(int i=n-1; i<=n and i<=k; i++){
        int current=i;
        while(current <= k){
            ans += bin(k, current) * i / total;
            current+=2;
        }
    }
    printf("%.8lf\n", ans);
    return 0;
}
