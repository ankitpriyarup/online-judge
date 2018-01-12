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
#include <iostream>

using namespace std;
using ll = long long;

bool done[1005][3][3];
int cases, many, V[1005], N[1005], save[1005][3][3];
char Z[10];
string S[1005];
vector<string> vowels, cons;

bool can(string orig, string a){
    for(int i=0; i<6; i++){
        if(!(orig[i] == a[i] or a[i] == '?')){
            return false;
        }
    }
    return true;
}

int dp(int pos, int canV, int needV){
    if(done[pos][canV][needV])
        return save[pos][canV][needV];
    done[pos][canV][needV] = true;

    if(pos==many+1){
        if(!needV){
            save[pos][canV][needV] = 1;
        }
        else {
            save[pos][canV][needV] = 0;
        }
        return save[pos][canV][needV];
    }

    int noV = dp(pos+1, true, needV);
    int useV = canV ? dp(pos+1, false, false) : 0;
    int ans;
    if(noV*N[pos] < 0 or useV*V[pos] < 0){
        ans = -1;
    }
    else {
        noV *= N[pos];
        useV *= V[pos];

        ans = useV + noV;
        if(ans > 10000){
            ans = -1;
        }
    }
    save[pos][canV][needV] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    vowels = {"110101", "101101", "010101", "111011"};
    cons = {"110111", "110011", "110000", "101111", "101011", "101000", "010111", "010011", "010000", "111101", "111111", "111000"};

    cin>>cases;
    while(cases--){
        memset(done, 0, sizeof(done));
        cin>>many;
        for(int i=1; i<=many; i++){
            cin>>Z;
            S[i] = Z;

            V[i] = N[i] = 0;
            for(int e=0; e<vowels.size(); e++){
                if(can(vowels[e], S[i])){
                    ++V[i];
                }
            }
            for(int e=0; e<cons.size(); e++){
                if(can(cons[e], S[i])){
                    ++N[i];
                }
            }

        }
        int ans = dp(1, true, true);
        if(ans==-1){
            cout<<"CANNOT DECIPHER\n";
        }
        else{
            cout<<ans<<"\n";
        }

    }
    return 0;
}
