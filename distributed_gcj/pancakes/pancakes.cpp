#include <message.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include "pancakes.h"

const long long MASTER_NODE = 0;
const long long INF = 1e18 + 3;

using namespace std;

bool get_bounds(long long items, long long id, long long nodes, long long& start, long long& end) {
    if (nodes > items)
        nodes = items;

    start = items * id / nodes;
    end = items * (id + 1) / nodes;

    return id < nodes;
}

int main() {
    const long long nodes = NumberOfNodes();
    const long long id = MyNodeId();

    const long long num_pancakes = GetStackSize();
    const long long num_diners = GetNumDiners();

    long long start, end;
    if (!get_bounds(num_pancakes, id, nodes, start, end)) {
        PutLL(MASTER_NODE, -1);
        PutLL(MASTER_NODE, -1);
        Send(MASTER_NODE);
        return 0;
    }

    // printf("%lld %lld\n", start, end);

    long long rotations = 0LL;
    long long prev = -1LL;

    for (long long i = start; i < end; ++i) {
        long long cur = GetStackItem(i);
        if (cur < prev) {
            ++rotations;
        }

        prev = cur;
    }

    if (id == MASTER_NODE) {
        for (int node = 1; node < nodes; ++node) {
            Receive(node);
            long long local_rot = GetLL(node);
            long long start = GetLL(node);

            if (start == -1) continue;
            rotations += local_rot;

            long long p = GetStackItem(start - 1);
            long long c = GetStackItem(start);

            if (c < p)
                ++rotations;
        }

        printf("%lld\n", rotations + 1);
    } else {
        PutLL(MASTER_NODE, rotations);
        PutLL(MASTER_NODE, start);
        Send(MASTER_NODE);
    }

    return 0;
}
