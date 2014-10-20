#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N; 
    if(N < 4) {
        cout << "NO\n";
        return 0;
    }
    
    if(N % 2 == 0) {
        cout << "YES\n";
        cout << "4 * 3 = 12" << '\n';
        cout << "12 * 2 = 24" << '\n';
        cout << "24 * 1 = 24" << '\n';
        for(int i = 6; i <= N; i+= 2) {
            cout << i << " - " << (i - 1) << " = 1\n";
            cout << "24 * 1 = 24\n";
        }
    } else {
        cout << "YES\n";
        cout << "5 - 2 = 3" << '\n';
        cout << "3 - 1 = 2" << '\n';
        cout << "4 * 3 = 12" << '\n';
        cout << "12 * 2 = 24" << '\n';
        for(int i = 7; i <= N; i+=2) {
            cout << i << " - " << (i - 1) << " = 1\n";
            cout << "24 * 1 = 24\n";
        }
    }
    return 0;
}
