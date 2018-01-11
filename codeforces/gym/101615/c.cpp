#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
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
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

ull a, b;
unsigned long long S[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>a>>b;
    for(ull i=1; i<=1000000; i++){
        ull start = a%i;
        if(start!=0){
            start = i-start;
        }
        ull current = start;
        while(current <= 1000000){
            S[current] += i;
            if((a+current)/i > 1000000){
                S[current] += (a+current)/i;
            }
            current += i;
        }
    }
    ull upto = b-a;
    ull ans = 0;
    for(ull i=0; i<=upto; i++){
        ans = ans + S[i];
    }
    cout<<ans<<endl;
    return 0;
}
