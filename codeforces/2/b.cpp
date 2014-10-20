#include <iostream>
#include <stack>

using namespace std;
int N;

int a[1010][1010];
int dp2[1010][1010];
int dp5[1010][1010];
char p2[1010][1010];
char p5[1010][1010];

int count(int x, int d) {
    if (x == 0 || x % d != 0) return 0;
    int pow = d;
    int count = 0;
    while(x % pow == 0) {
        count++;
        pow *= d;
    }
    return count;
}

void print_boards() {
    cout << '\n';
    for(int i=0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << dp2[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    for(int i=0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << dp5[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    for(int i=0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << p2[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    for(int i=0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << p5[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    cin >> N;
    bool cornercase = false;
    int x = -1;
    int y = -1;
    for(int i=0;i<N;i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0) {
                cornercase = true;
                x = i;
                y = j;
            }
        }
    }

    dp2[0][0] = count(a[0][0], 2);
    dp5[0][0] = count(a[0][0], 5);
    for(int i=1;i<N;i++) {
        dp2[0][i] = dp2[0][i - 1] + count(a[0][i], 2);
        dp5[0][i] = dp5[0][i - 1] + count(a[0][i], 5);
        p2[0][i] = 'R';
        p5[0][i] = 'R';
        
        dp2[i][0] = dp2[i - 1][0] + count(a[i][0], 2);
        dp5[i][0] = dp5[i - 1][0] + count(a[i][0], 5);
        p2[i][0] = 'D';
        p5[i][0] = 'D';
    }

    for(int i=1; i < N; i++) {
        for(int j = 1; j < N; j++) {
            if(dp2[i - 1][j] < dp2[i][j - 1]) {
                dp2[i][j] = dp2[i - 1][j] + count(a[i][j], 2);
                p2[i][j] = 'D';
            } else {
                dp2[i][j] = dp2[i][j - 1] + count(a[i][j], 2);
                p2[i][j] = 'R';
            }

            if(dp5[i - 1][j] < dp5[i][j - 1]) {
                dp5[i][j] = dp5[i - 1][j] + count(a[i][j], 5);
                p5[i][j] = 'D';
            } else {
                dp5[i][j] = dp5[i][j - 1] + count(a[i][j], 5);
                p5[i][j] = 'R';
            }
        }
    }
    
//    print_boards();
    stack<char> s;
    if(dp2[N - 1][N - 1] != 0 && dp5[N - 1][N - 1] != 0 && cornercase) {
        cout << "1\n";
        for(int i=0;i<x;i++) {
            cout << 'D';
        }
        for(int i=0;i<y;i++) {
            cout << 'R';
        }
        for(int i=x+1;i<N;i++) {
            cout << 'D';
        }
        for(int i=y+1;i<N;i++) {
            cout << 'R';
        }
        cout << '\n';
        return 0;
    }

    if(dp2[N - 1][N - 1] < dp5[N - 1][N - 1]) {
        cout << dp2[N - 1][N - 1] << '\n';
        int x = N - 1;
        int y = N - 1;
        while (x != 0 || y != 0) {
            s.push(p2[x][y]);
            if(p2[x][y] == 'D') {
                x--;
            } else {
                y--;
            }
        }
        while(!s.empty()) {
            cout << s.top();
            s.pop();
        }
    } else {
        cout << dp5[N - 1][N - 1] << '\n';
        int x = N - 1;
        int y = N - 1;
        while (x != 0 || y != 0) {
            s.push(p5[x][y]);
            if(p5[x][y] == 'D') {
                x--;
            } else {
                y--;
            }
        }
        while(!s.empty()) {
            cout << s.top();
            s.pop();
        }

    }
    cout << '\n';
    return 0;
}
