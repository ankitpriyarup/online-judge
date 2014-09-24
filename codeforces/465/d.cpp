#include <iostream>
#define P 8
#define C 3
using namespace std;
long long coords[8][3];
int permutation[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
int current[] = {0, 0, 0, 0, 0, 0, 0, 0};

void printans() {
    cout << "YES\n";
    for(int i=0;i<P; i++) {
        cout << coords[i][permutation[current[i]][0]] << " "
        << coords[i][permutation[current[i]][1]] << " "
        << coords[i][permutation[current[i]][2]] << '\n';
    }
}

long long square(long long x) {
    return 1LL * x * x;
}

bool isgood() {
    //calculate all the squared differences and see if they make sense
    long long dists[] = {0, 0, 0};
    long long counts[] = {0, 0, 0};
    for(int i=0;i<P;i++) {
        for(int j=i+1;j<P;j++) {
            long long dist = 
                square(coords[i][permutation[current[i]][0]] - coords[j][permutation[current[j]][0]]) + 
                square(coords[i][permutation[current[i]][1]] - coords[j][permutation[current[j]][1]]) + 
                square(coords[i][permutation[current[i]][2]] - coords[j][permutation[current[j]][2]]);
            bool inserted = false;
            for(int k=0;k<3;k++) {
                if(dists[k] == dist) {
                    counts[k]++;
                    inserted = true;
                    break;
                } else if(dists[k] == 0) {
                    dists[k] = dist;
                    counts[k] = 1;
                    inserted = true;
                    break;
                }
            }
            if(!inserted) return false;
        }
    }
    if(counts[0] + counts[1] + counts[2] != 28) return false;
    for(int i=0;i<6;i++) {
        if(dists[permutation[i][0]] * 2 == dists[permutation[i][1]]
                && dists[permutation[i][0]] * 3 == dists[permutation[i][2]]
                && counts[permutation[i][0]] == 12 && counts[permutation[i][1]] == 12 && counts[permutation[i][2]] == 4) {
            return true; 
        }
    }
    return false;
}

bool increment() {
    int i = P-1;
    current[i]++;
    while(current[i] == 6) {
        current[i] = 0;
        i--;
        if(i < 0) {
            return false;
        }
        current[i]++;
    }
    return true;
}

int main() {
    for(int i=0;i<P;i++) {
        for(int j=0;j<C;j++) {
            cin >> coords[i][j];
        }
    }
    if(isgood()) {
        printans();
        return 0;
    }
    bool done = false;
    while(increment()) {
        if(isgood()) {
            done = true;
            printans();
            break;
        }
    }
    if(!done) {
        cout << "NO" << '\n';
    }
    return 0;
}
