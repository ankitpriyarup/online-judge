#include <iostream>
#include <string>

using namespace std;
int N, P;
int a[1001];
string s;
int main() {
    cin >> N >> P;
    cin >> s;
    for(int i=0;i<N;i++) {
        a[i] = s[i] - 'a';
    }
    bool tolerable = false;;
    while(!tolerable) {
        int i = N - 1;
        a[i]++;
        while(a[i] >= P) {
            a[i] = 0;
            i--;
            if(i < 0) {
                cout << "NO\n";
                return 0;
            }
            a[i]++;
        }
        tolerable = true;
        //check for doubles and triples
        for(int mid=1;mid<N-1;mid++) {
            if(a[mid-1] == a[mid+1] || a[mid-1] == a[mid] || a[mid] == a[mid+1]) tolerable = false;
        }
        if(N >= 2 && a[0] == a[1]) tolerable = false;
    }
    for(int i=0;i<N;i++) {
        cout << ((char)(a[i] + 'a'));
    }
    cout << '\n';
    return 0;
}
