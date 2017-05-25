#include <message.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include "pancakes.h"

const int MASTER_NODE = 0;
const long long INF = 1e18 + 3;

using namespace std;

int main() {
    const int nodes = NumberOfNodes();
    const int id = MyNodeId();

    const long long num_pancakes = GetStackSize();
    const long long num_diners = GetNumDiners();

    if (id == MASTER_NODE) {
        long long rotations = 1LL;
        long long prev = -1LL;
        for (int i = 0; i < num_pancakes; ++i) {
            long long cur = GetStackItem(i);
            if (cur < prev) {
                ++rotations;
            }

            prev = cur;
        }

        printf("%lld\n", rotations);
    } else {
    }

    return 0;
}
