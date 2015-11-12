/*
ID: rednano1
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
const int MAX_N = 10;
string names[MAX_N];
map<string, int> money;

int main(){
    ifstream fin  ("gift1.in");
    ofstream fout ("gift1.out");

    int N;
    fin >> N;

    string name;
    for (int i = 0; i < N; i++) {
        fin >> name;
        names[i] = name;
    }

    string giver, receiver;
    int total_money, num_receivers, gift_cost;
    for (int i = 0; i < N; i++) {
        fin >> giver;
        fin >> total_money >> num_receivers;
        if (total_money == 0 || num_receivers == 0) {
          continue;
        }

        gift_cost = total_money / num_receivers;
        
        for (int j = 0; j < num_receivers; j++) {
            fin >> receiver;
            money[giver] -= gift_cost;
            money[receiver] += gift_cost;
        }
    }

    for (int i = 0; i < N; i++) {
        fout << names[i] << ' ' << money[names[i]] << '\n';
    }

    return 0;
}
