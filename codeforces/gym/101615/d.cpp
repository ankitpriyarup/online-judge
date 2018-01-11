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
using ld = long double;
using pii = pair<int, int>;

struct par {
    int x, c;
} m;

ll n;
vector<par> L[50005];
int badr = 0;
vector<int> ans;
map<int, int> M[50005];

void aslo(int dnde, int parent, int parentc){
    for(int i=0; i<L[dnde].size(); i++){
        if(L[dnde][i].x == parent) continue;
        if(parentc == L[dnde][i].c){
            ++badr;
        }
        aslo(L[dnde][i].x, dnde, L[dnde][i].c);
    }
}

void tran(int dnde, int parent, int parentc, int bad){
    if(bad==0){
        ans.push_back(dnde);
    }
    for(int i=0; i<L[dnde].size(); i++){
        int child = L[dnde][i].x, edgec = L[dnde][i].c;
        if(child == parent) continue;
        int nbad = bad;
        nbad -= (M[child][edgec]-1);
        nbad += (M[dnde][edgec]-1);
        tran(L[dnde][i].x, dnde, L[dnde][i].c, nbad);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1; i<n; i++){
        int a, b;
        cin>>a>>b>>m.c;
        m.x = b;
        L[a].push_back(m);
        m.x = a;
        L[b].push_back(m);

        M[a][m.c]++;
        M[b][m.c]++;
    }

    aslo(1, -1, -1);
    tran(1, -1, -1, badr);
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
