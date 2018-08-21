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

char A[1005], C[1005];
vector<int> P[300];
int B[1005], n, Z[300];
int M[1005];
int many = 0;
void pri(int x, int y){
    if (x!=y){
        if(C[x] > C[y])
            cout<<x+1<<" "<<y+1<<"\n";
        else
            cout<<y+1<<" "<<x+1<<"\n";
        ++many;
        swap(C[x], C[y]);
    }
}

void sor(int x, int y){
    if(x==y)
        return;
    int mid=(x+y)/2;
    sor(x, mid);
    sor(mid+1, y);
    for(int i=x; i<=y;i++){
        M[i] = B[i];
    }
    int a=x, b=mid+1;
    int pos = x;
    while(a<=mid){
        if(a <= mid and (b > y or B[a] < B[b])){
            //pri(a, pos);
            ++a;
        }
        else{
            pri(b, pos);
            swap(B[b], B[pos]);
            ++a;
        }
        ++pos;
    }
    while(b<y){
        if(B[b]>B[b+1]){
            pri(b, b+1);
            swap(B[b], B[b+1]);
            ++b;
        }
        else 
            break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>A;
    for(n=0; A[n]!='\0'; n++){
        C[n] = A[n];
    }
    sort(C, C+n);

    for(int i=0; i<n; i++){
        P[A[i]].push_back(i);
    }

    for(int i=0; i<n; i++){
        B[i] = P[C[i]][Z[C[i]]];
        Z[C[i]]++;
    }
    
    for(int i=0; i<n; i++){
        for(int e=0; e<n; e++){
            if(B[e]==i){
                if(e!=i){
                    pri(e, i);
                    swap(B[e], B[i]);
                }
                break;
            }
        }
    }

    //sor(0, n-1);
    bool eq = true;
    for(int i=0; i<n; i++){
        if(C[i]!=A[i]) eq=false;
    }
    while(!eq){
    }
    if(many>10000){
        cout<<5/0<<"\n";
    }
    return 0;
}
